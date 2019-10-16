//https://www.spoj.com/problems/ADACROP/
#include <chrono>
#include <random>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#define MAX_INT 2147483647
#define N 200010
using namespace std;
using namespace __gnu_pbds;

/**
*	Función para eficientar el hashing de las tablas hash.
*	https://codeforces.com/blog/entry/60737
*/
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

int A[N];

int randInt() {
	static random_device ran;
	static mt19937 gen( ran() );
	static uniform_int_distribution<> dis( 0 , MAX_INT );
	return dis( gen );
}

struct node {
	
	int val;
	int weight,size;
	node *l,*r;
	gp_hash_table<int, int,chash> table;
	
	node(int v) {
		val=v;
		l=r=NULL;
		weight=randInt();
	}
	
};

inline int size(node *it) {
	return it?it->size:0;
}

void print( node *it ) {
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

node* build(int *A,int n) {
	if(n==0) return NULL;
	int m=n/2;
	node *it=new node(A[m]);
	it->l=build(A,m);
	it->r=build(A+m+1,n-m-1);
	//heapify(it);
	it->size=size(it->l)+size(it->r)+1;
	
	if(it->l) {
		for(auto i:it->l->table) 
			it->table[i.first]+=i.second;
	}
	if(it->r) {
		for(auto i:it->r->table) 
			it->table[i.first]+=i.second;
	}
	it->table[it->val]++;
	return it;
}

int query(node *it,int i,int j,int val,int sum=0) {
	if(i>j)
		return 0;
	int index=sum+size(it->l);
	int leftIndex=index-size(it->l),rightIndex=index+size(it->r);
	int res=0;
	if(i==leftIndex && j==rightIndex)	//Encontró el rango
		res+=it->table[val];
	else if(index < i) 	//Buscar a la derecha
		res+=query(it->r,i,j,val,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=query(it->l,i,j,val,sum);
	else {
		res+=(it->val == val);
		if(i < index) 	//Dividir a la izquierda
			res+=query(it->l,i,index-1,val,sum);
		if(index < j) 	//Dividir a la derecha
			res+=query(it->r,index+1,j,val,index+1);
	}
	return res;
}

int update(node *it,int i,int val,int sum=0) {
	int index=sum+size(it->l);
	int res=0;
	if(index == i) {
		res=it->val;
		it->val=val;
	}
	else if(i < index) 	//Buscar a la izquierda
		res=update(it->l,i,val,sum);
	else 	//Buscar a la derecha
		res=update(it->r,i,val,index+1);
	it->table[res]--;
	it->table[val]++;
	return res;
}

int main() {
	int n,x,q,a,b;
	scanf("%d %d",&n,&q);
	for(x=0;x<n;x++) 
		scanf("%d",A+x);
	node *treap=build(A,n);
	while(q--) {
		scanf("%d %d",&a,&b);
		printf("%d\n",query(treap,0,a-1,b));
		update(treap,a,b);
	}
	return 0;
}
