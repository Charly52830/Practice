//https://www.spoj.com/problems/ADAAPHID/
#include<random>
#include<iostream>
#define mp make_pair
#define MAX_INT 2147483647
#define N 300010
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;

int randInt() {
	static random_device ran;
	static mt19937 gen( ran() );
	static uniform_int_distribution<> dis( 0 , MAX_INT );
	return dis( gen );
}

struct node {
	ll a,v;
	int weight,size;
	ll *A,*B;
	int n;
	node *l,*r;
	
	node(pl p) {
		l=r=NULL;
		weight=randInt();
		size=1;
		a=p.first,v=p.second;
		A=B=NULL;
	}
};

void print( node *it ) {
	if( it->l != NULL ) 
		print( it->l );
	cout<< it->a <<" ";
	if( it->r != NULL ) 
		print( it->r );
}

ll L[N];
node *treap;

inline int size( node *it ) {
	return it?it->size:0;
}

inline int size_n(node *it) {
	return it?it->n:0;
}

inline pl get_val(node *it,int i) {
	if(!it)
		return mp(0,0);
	if(i>0)
		return mp(it->A[i],it->B[i]-it->B[i-1]);
	else
		return mp(it->A[i],it->B[i]);
}

inline ll getL(int i) {
	if(i<0)
		return 0LL;
	else
		return L[i];
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

node* build(pl *A,int n) {
	if(n==0) return NULL;
	int m=n/2;
	node *it=new node(A[m]);
	it->l=build(A,m);
	it->r=build(A+m+1,n-m-1);
	heapify(it);
	it->size=size(it->l)+size(it->r)+1;
	return it;
}

void combine_left(node *it) {
	int n=size_n(it->l)+1; 
	ll cur_a=it->a,cur_b=it->v;
	ll *A=(ll*)malloc(n*sizeof(ll));
	ll *B=(ll*)malloc(n*sizeof(ll));
	for(int x=0;x<n-1;x++) {
		pl p=get_val(it->l,x);
		if(p.first > cur_a) 
			swap(p.first,cur_a),swap(p.second,cur_b);
		A[x]=p.first,B[x]=p.second;
		if(x>0)
			B[x]+=B[x-1];
	}
	A[n-1]=cur_a,B[n-1]=cur_b;
	if(n-1>0)
		B[n-1]+=B[n-2];
	it->A=A,it->B=B;
	it->n=n;
}

void combine_right(node *it) {
	int n=size_n(it)+size_n(it->r);
	ll *A=(ll*)malloc(n*sizeof(ll));
	ll *B=(ll*)malloc(n*sizeof(ll));
	int i=0,j=0,size_i=size_n(it),size_j=size_n(it->r),x=0;
	while(i<size_i || j<size_j) {
		pl pi=get_val(it,i),pj=get_val(it->r,j);
		if(i<size_i && j<size_j) {
			if(pi.first < pj.first)
				A[x]=pi.first,B[x]=pi.second,i++;
			else
				A[x]=pj.first,B[x]=pj.second,j++;
		}
		else if(i<size_i) 
			A[x]=pi.first,B[x]=pi.second,i++;
		else 
			A[x]=pj.first,B[x]=pj.second,j++;
		if(x>0)
			B[x]+=B[x-1];
		x++;
	}
	it->n=n;
	it->A=A,it->B=B;
}

ll count(node *it,int i,int j,ll val,int sum=0) {
	if(i>j)
		return 0LL;
	int index = sum + size( it->l );
	ll res=0;
	int leftIndex= index - size( it->l ), rightIndex= index + size( it->r );
	if(i == leftIndex && j== rightIndex) {
		int inf=-1,sup=it->n-1;
		while(sup-inf>1) {
			int m=inf+sup>>1;
			if(it->A[m] > val)
				sup=m;
			else
				inf=m;
		}
		if(it->A[sup]<=val)
			res+=it->B[sup];
		else if(inf>-1)
			res+=it->B[inf];
	}
	else if(index < i) 	//Buscar a la derecha
		res+=count(it->r,i,j,val,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=count(it->l,i,j,val,sum);
	else {
		//res+=treap->value <=val;
		if(it->a <=val)
			res+=it->v;
		if(i < index) 	//Dividir a la izquierda
			res+=count(it->l,i,index-1,val,sum);
		if(index < j) 	//Dividir a la derecha
			res+=count(it->r,index+1,j,val,index+1);
	}
	return res;
}

void solve(node *it,int sum=0) {
	if(it == NULL) 
		return;
	int index = sum + size( it->l );
	solve(it->l,sum);
	ll l=getL(index-1);
	it->a^=l,it->v^=l;
	L[index]=count(treap,0,index-1,it->a) + it->v;
	combine_left(it);
	cout<<it->a <<" "<<L[index]<<endl;
	solve(it->r,index+1);
	combine_right(it);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	ll a,b;
	cin>>n;
	pl A[n];
	for(x=0;x<n;x++) {
		cin>>a>>b;
		A[x]=mp(a,b);
	}
	treap=build(A,n);
	solve(treap);
	return 0;
}
