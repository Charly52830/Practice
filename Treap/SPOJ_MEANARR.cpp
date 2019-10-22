//https://www.spoj.com/problems/MEANARR/
#include<random>
#include<iostream>
#define MAX_INT 2147483647
#define N 200010
using namespace std;

typedef long long ll;

int randInt() {
	static random_device ran;
	static mt19937 gen( ran() );
	static uniform_int_distribution<> dis( 0 , MAX_INT );
	return dis( gen );
}

struct node {
	
	ll val;
	int weight,size;
	node *l,*r;
	ll *A;
	
	node(ll v) {
		val=v;
		l=r=NULL;
		weight=randInt();
		size=1;
	}
	
};

inline int size(node *it) {
	return it?it->size:0;
}

inline ll get_val(node *it,int i) {
	if(it && i<size(it))
		return it->A[i];
	return -MAX_INT;
}

void print( node *it ) {
	if(!it)
		return;
	if( it->l != NULL ) 
		print( it->l );
	cout<< it->val <<" ";
	if( it->r != NULL ) 
		print( it->r );
}

void heapify(node *it) {
	node *min=it;
	do {
		swap(it->weight,min->weight);
		it=min;
		if(it->l != NULL && it->l->weight < min->weight)
			min=it->l;
		if(it->r != NULL && it->r->weight < min->weight)
			min=it->r;
	}while(min!=it);
}

node* build(ll *A,int n) {
	if(n==0) return NULL;
	int m=n/2;
	node *it=new node(A[m]);
	it->l=build(A,m);
	it->r=build(A+m+1,n-m-1);
	heapify(it);
	it->size=size(it->l)+size(it->r)+1;
	
	//Preprocesamiento
	it->A=(ll*)malloc(it->size * sizeof(ll));
	int k=0;
	int i=0,j=0,size_i=size(it->l),size_j=size(it->r);
	ll tmp_val=it->val;
	while(i<size_i || j<size_j) {
		ll a=get_val(it->l,i),b=get_val(it->r,j);
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

int query(node *it,int i,int j,ll val,int sum=0) {
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

ll A[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,x;
	cin>>n>>k;
	for(x=0;x<n;x++) {
		cin>>A[x];
		A[x]-=k;
		if(x)
			A[x]+=A[x-1];
	}
	node *treap=build(A,n);
	ll res=0;
	ll K=0;
	for(x=0;x<n;x++) {
		res+=query(treap,x,n-1,K);
		A[x]=A[x]-K;
		K+=A[x];
	}
	cout<<res<<endl;
	return 0;
}
