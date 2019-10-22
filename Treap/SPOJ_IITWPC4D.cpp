//https://www.spoj.com/problems/IITWPC4D/
#include<random>
#include<iostream>
#define MAX_INT 2147483647
#define N 100010
using namespace std;
 
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
	int sum;
	
	node(int v) {
		val=v;
		l=r=NULL;
		weight=randInt();
		size=1;
		sum=1;
	}
	
};
 
inline int size(node *it) {
	return it?it->size:0;
}
 
inline int get_sum(node *it) {
	return it?it->sum:0;
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
 
node* build(int *A,int n) {
	if(n==0) return NULL;
	int m=n/2;
	node *it=new node(A[m]);
	it->l=build(A,m);
	it->r=build(A+m+1,n-m-1);
	//heapify(it);
	it->size=size(it->l)+size(it->r)+1;
	it->sum=get_sum(it->l) + get_sum(it->r)+it->val;
	return it;
}
 
void update(node *it,int i,int sum=0) {
	int index=sum+size(it->l);
	it->sum--;
	if(index == i)
		it->val--;
	else if(index < i)
		update(it->r,i,index+1);
	else if(index > i)
		update(it->l,i,sum);
}
 
int query(node *it,int i,int j,int sum=0) {
	if(i>j)
		return 0;
	int index=sum+size(it->l);
	int leftIndex=index-size(it->l),rightIndex=index+size(it->r);
	int res=0;
	if(i==leftIndex && j==rightIndex) 	//EncontrÃ³ el rango
		res+=it->sum;
	else if(index < i) {	//Buscar a la derecha
		res+=query(it->r,i,j,index+1);
	}
	else if(index > j) {	//Buscar a la izquierda
		res+=query(it->l,i,j,sum);
	}
	else {
		res+=it->val;
		if(i < index) 	//Dividir a la izquierda
			res+=query(it->l,i,index-1,sum);
		if(index < j) 	//Dividir a la derecha
			res+=query(it->r,index+1,j,index+1);
	}
	return res;
}
 
int A[N],B[N],res[N];
 
int main() {
	int t,j,x,n;
	scanf("%d",&t);
	for(j=0;j<t;j++) {
		bool bul=0;
		scanf("%d",&n);
		for(x=0;x<n;x++) {
			scanf("%d",A+x),B[x]=1;
			bul|=A[x]>x;
		}
		printf("Test : %d\n",j+1);
		if(bul) {
			printf("-1\n");
			continue;
		}
		node *treap=build(B,n);
		for(x=n-1;x>=0;x--) {
			int i=0,f=n-1;
			while(f-i>1) {
				int m=i+f>>1;
				if(query(treap,m+1,n-1)<=A[x])
					f=m;
				else
					i=m;
			}
			if(i!=f && query(treap,f,n-1) == A[x]) 
				f--;
			res[x]=f;
			update(treap,f);
		}
		for(x=0;x<n;x++)
			printf("%d ",res[x]+1);
		printf("\n");
	}
	return 0;
}
