//https://omegaup.com/arena/omegacup1/practice/#problems/Tu-y-tu-Futuro
#include<vector>
#include<iostream>
#define N 500001
#define mp make_pair
#define pb push_back
#define MAX_INT 2147483647
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll *BS;
int R[N],D[N];
int tam[N],ID[N],sz;
int depth[N];

int binary_search(int d,ll k) {
	if(d > 0 && BS[d] - BS[d-1] > 1000000000)
		return d + 1;
	int i=0,f=d;
	while(i<f) {
		int m=(i+f)/2;
		if(BS[d] - (m==0?0:BS[m-1]) <= k)
			f=m;
		else
			i=m+1;
	}
	if(k >= BS[i] - (i==0?0:BS[i-1]))
		return i;
	return i + 1;
}

struct node {
	
	int val,size;
	node *l,*r;
	int *A;
	
	node(int v) {
		val=v;
		l=r=NULL;
		size=1;
	}
	
};

inline int size(node *it) {
	return it?it->size:0;
}

inline int get_val(node *it,int i) {
	if(it && i<size(it))
		return it->A[i];
	return -MAX_INT;
}

node* build(int *A,int n) {
	if(n==0) return NULL;
	int m=n/2;
	node *it=new node(A[m]);
	it->l=build(A,m);
	it->r=build(A+m+1,n-m-1);
	it->size=size(it->l)+size(it->r)+1;
	
	//Preprocesamiento
	it->A=(int*)malloc(it->size * sizeof(int));
	int k=0;
	int i=0,j=0,size_i=size(it->l),size_j=size(it->r);
	int tmp_val=it->val;
	while(i<size_i || j<size_j) {
		int a=get_val(it->l,i),b=get_val(it->r,j);
		if(i<size_i && j<size_j) {
			if(a<b)
				it->A[k]=a,i++;
			else
				it->A[k]=b,j++;
		}
		else if(i<size_i) 
			it->A[k]=a,i++;
		else 
			it->A[k]=b,j++;
		
		if(it->A[k]>tmp_val)
			swap(it->A[k],tmp_val);
		k++;
	}
	it->A[k]=tmp_val;
	return it;
}

int query(node *it,int i,int j,int val,int sum=0) {
	int index=sum+size(it->l);
	int leftIndex=index-size(it->l),rightIndex=index+size(it->r);
	int res=0;
	if(i==leftIndex && j==rightIndex) {	//Encontró el rango
		int inf=0,sup=size(it)-1;
		while(inf<sup) {
			int m=inf+sup>>1;
			if(it->A[m] < val)
				inf=m+1;
			else
				sup=m;
		}
		if(it->A[inf]>=val)
			res+=size(it)-inf;
	}
	else if(index < i) 	//Buscar a la derecha
		res+=query(it->r,i,j,val,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=query(it->l,i,j,val,sum);
	else {
		res+=it->val>=val;
		if(i < index) 	//Dividir a la izquierda
			res+=query(it->l,i,index-1,val,sum);
		if(index < j) 	//Dividir a la derecha
			res+=query(it->r,index+1,j,val,index+1);
	}
	return res;
}

int dfs(int n,vector<vector<pii> > &v, int d=0) {
	int index=sz++;
	tam[index] = 1;
	ID[index] = n;
	depth[index] = d;
	if(d > 0)
		D[index] = binary_search(d - 1,R[n]);
	for(auto p:v[n]) {
		int a=p.first;	// nodo
		BS[d]=p.second;	// costo
		if(d > 0)
			BS[d]+=BS[d-1];
		tam[index]+=dfs(a,v,d+1);
	}
	return tam[index];
}

int main() {
	int n,p,d;
	scanf("%d",&n);
	{
		BS=(ll*)malloc(n * sizeof(ll));
		vector<vector<pii> > v;
		v.resize(n+1);
		for(int x=1;x<n;x++) {
			scanf("%d %d %d",&p,&d,R+x);
			v[p].pb(mp(x,d));
		}
		dfs(0,v);
		free(BS);
	}
	node *treap=build(D,n);
	for(int x=0;x<n;x++) 
		R[ID[x]] = tam[x] -1 - query(treap,x,x+tam[x]-1,depth[x] + 1);
	for(int x=0;x<n;x++)
		printf("%d ",R[x]);
	printf("\n");
	return 0;
}
