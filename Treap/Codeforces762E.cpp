//https://codeforces.com/contest/762/problem/E
#include <algorithm>
#include <tuple>
#include <random>
#include <vector>
#include <iostream>
#define N 100010
#define MAX_INT 2147483647
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

ti mt(int a,int b,int c) {
	ti t;
	get<0>(t)=a;
	get<1>(t)=b;
	get<2>(t)=c;
	return t;
}

int randInt() {
	static random_device ran;
	static mt19937 gen( ran() );
	static uniform_int_distribution<> dis( 0 , MAX_INT );
	return dis( gen );
}

int X[N],R[N],F[N];
pii A[N];
ti T[N];

struct node {
	node *l, *r;
	node *treap;
	int weight, size;
	int val1,val2;
	int *A,*B,*C;
	int value;
	int n;
	
	node(int v) {
		l=r=NULL;
		weight=randInt();
		value=v;
		size=1;
	}
	
	node(int v1,int v2) {
		l=r=NULL;
		weight=randInt();
		val1=v1,val2=v2;
		size=1;
	}	
};

void print( node *treap ) {
	if( treap->l != NULL ) 
		print( treap->l );
	cout<< treap->val1 <<": ";
	for(int x=0;x<treap->n;x++) 
		printf("%d,%d ",treap->A[x],treap->B[x]);
	printf("\n");
	if( treap->r != NULL ) 
		print( treap->r );
}

void print2( node *treap ) {
	if( treap->l != NULL ) 
		print2( treap->l );
	cout<< treap->value<<": ";
	for(int x=0;x<treap->n;x++) 
		printf("%d ",treap->C[x]);
	printf("\n");
	if( treap->r != NULL ) 
		print2( treap->r );
}

inline int size( node *it ) {
	return it?it->size:0;
}

inline int vSize(node *it) {
	return it?it->n:0;
}

inline pii nums(node *it,int i) {
	return it?mp(it->A[i],it->B[i]):mp(1000000010,1000000010);
}

inline int nums2(node *it,int i) {
	return it?it->C[i]:MAX_INT;
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

node* build(pii *a,int n) {
	if(n==0)
		return NULL;
	int m=n/2;
	node *nod=new node(a[m].first,a[m].second);	
	nod->l = build(a,m);
	nod->r = build(a+m+1,n-m-1);
	heapify(nod);
	nod->size=size(nod->l) + size(nod->r)+1;
	return nod;
}

node* build(int *a,int n) {
	if(n==0)
		return NULL;
	int m=n/2;
	node *nod=new node(a[m]);	
	nod->l = build(a,m);
	nod->r = build(a+m+1,n-m-1);
	heapify(nod);
	nod->size=size(nod->l) + size(nod->r)+1;
	return nod;
}

void combine2(node *it) {
	if(it->l != NULL)
		combine2(it->l);
	if(it->r != NULL)
		combine2(it->r);
	vector<int> C;
	int i=0,lSize=vSize(it->l),j=0,rSize=vSize(it->r);
	int val=it->value;
	while(i<lSize || j<rSize) {
		int l=nums2(it->l,i),r=nums2(it->r,j);
		if(i<lSize && j<rSize) {
			if(l < r)
				C.pb(l),i++;
			else
				C.pb(r),j++;
		}
		else if(i<lSize) 
			C.pb(l),i++;
		else 
			C.pb(r),j++;
		if(C[C.size()-1] > val)
			swap(C[C.size()-1],val);
	}
	C.push_back(val);
	it->C=(int*)malloc(C.size()*sizeof(int));
	it->n=C.size();
	for(int x=0;x<C.size();x++)
		it->C[x]=C[x];
}

void combine(node *it) {
	if(it->l != NULL)
		combine(it->l);
	if(it->r != NULL)
		combine(it->r);
	vector<int> A,B;
	int i=0,lSize=vSize(it->l),j=0,rSize=vSize(it->r);
	int val1=it->val1,val2=it->val2;
	while(i<lSize || j<rSize) {
		pii l=nums(it->l,i),r=nums(it->r,j);
		if(i<lSize && j<rSize) {
			if(l.first < r.first)
				A.pb(l.first),B.pb(l.second),i++;
			else
				A.pb(r.first),B.pb(r.second),j++;
		}
		else if(i<lSize) 
			A.pb(l.first),B.pb(l.second),i++;
		else 
			A.pb(r.first),B.pb(r.second),j++;
		if(A[A.size()-1] > val1)
			swap(A[A.size()-1],val1),swap(B[B.size()-1],val2);
	}
	A.pb(val1),B.pb(val2);
	it->A=(int*)malloc(A.size()*sizeof(int));
	it->B=(int*)malloc(B.size()*sizeof(int));
	it->n=A.size();
	for(int x=0;x<A.size();x++)
		it->A[x]=A[x],it->B[x]=B[x];
	it->treap=build(it->B,it->n);
	combine2(it->treap);
}

int count(node *treap,int i,int j,int val,int sum=0) {
	int index = sum + size( treap->l );
	int res=0;
	int leftIndex= index - size( treap->l ), rightIndex= index + size( treap->r );
	if(i == leftIndex && j== rightIndex) {		
		int inf=-1,sup=treap->n-1;
		while(sup-inf>1) {
			int m=inf+sup>>1;
			if(treap->C[m] > val)
				sup=m;
			else
				inf=m;
		}
		if(treap->C[sup]<=val)
			res+=sup+1;
		else
			res+=inf+1;
	}
	else if(index < i) 	//Buscar a la derecha
		res+=count(treap->r,i,j,val,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=count(treap->l,i,j,val,sum);
	else {
		res+=treap->value <=val;
		if(i < index) 	//Dividir a la izquierda
			res+=count(treap->l,i,index-1,val,sum);
		if(index < j) 	//Dividir a la derecha
			res+=count(treap->r,index+1,j,val,index+1);
	}
	return res;
}

int query(node *treap,int i,int j,int val,int fk,int FK,int sum=0) {
	int index = sum + size( treap->l );
	int res=0;
	int leftIndex= index - size( treap->l ), rightIndex= index + size( treap->r );
	if(i == leftIndex && j== rightIndex) {
		int tmp_res;
		int inf=-1,sup=treap->n-1;
		while(sup-inf>1) {
			int m=inf+sup>>1;
			if(treap->A[m] > val)
				sup=m;
			else
				inf=m;
		}
		if(treap->A[sup]<=val)
			tmp_res=sup;
		else
			tmp_res=inf;
		if(tmp_res>=0)
			res+=count(treap->treap,0,tmp_res,FK) - count(treap->treap,0,tmp_res,fk-1);
	}
	else if(index < i) 	//Buscar a la derecha
		res+=query(treap->r,i,j,val,fk,FK,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=query(treap->l,i,j,val,fk,FK,sum);
	else {		
		if(treap->val1 <=val && fk <= treap->val2 && treap->val2 <=FK)
			res++;
		if(i < index) 	//Dividir a la izquierda
			res+=query(treap->l,i,index-1,val,fk,FK,sum);
		if(index < j) 	//Dividir a la derecha
			res+=query(treap->r,index+1,j,val,fk,FK,index+1);
	}
	return res;
}

int main() {
	int n,k,x,a,b,c;
	scanf("%d %d",&n,&k);
	for(x=0;x<n;x++) {
		scanf("%d %d %d",&a,&b,&c);
		T[x]=mt(a,b,c);
	}
	sort(T,T+n);
	for(x=0;x<n;x++) {
		X[x]=get<0>(T[x]);
		R[x]=get<1>(T[x]);
		F[x]=get<2>(T[x]);
		A[x]=mp(X[x]-R[x],F[x]);
	}
	node *treap=build(A,n);
	combine(treap);
	long long sum=0;
	for(x=0;x<n-1;x++) {
		int val=X[x]+R[x];	
		int i=x,f=n-1;
		while(f-i>1) {
			int m=i+f>>1;
			if(X[m]<=val)
				i=m;
			else
				f=m;
		}
		if(X[f]<=val)
			i++;
		if(i>x)
			sum+=query(treap,x+1,i,X[x],F[x]-k,F[x]+k);
	}
	cout<<sum<<endl;	
	return 0;
}
