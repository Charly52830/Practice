//https://codeforces.com/contest/847/problem/D
#include <random>
#include <vector>
#include <iostream>
#define MAX_INT (1LL<<31)-1
#define N 200010
#define oo 2000000010
#define mp make_pair
#define pb push_back
using namespace std;

typedef pair<int,int> pii;

int A[N];

int randInt() {
	static random_device ran;
	static mt19937 gen( ran() );
	static uniform_int_distribution<> dis( 0 , MAX_INT );
	return dis( gen );
}

struct node {
	node *left, *right;
	int weight, size,value;
	vector<int> nums,freq;
	
	node( int v ) {
		left = right = NULL;
		weight = randInt();
		value = v;
		size = 1;
	}
	
};

void print( node *treap ) {
	if( treap->left != NULL ) 
		print( treap->left );
	cout<< treap->value <<" ";
	if( treap->right != NULL ) 
		print( treap->right );
}

//Tamaño del subárbol de un nodo.
int size( node *treap ) {
	if( treap==NULL )
		return 0;
	return treap->size;
}

/**
*	Separa el nodo treap en 2 treaps.
*	En el nodo left queda guardado el treap con los primeros k nodos.
*	En el nodo right queda guardado el resto del treap.
*	O(log n) en promedio
*/
void split( node *treap, node *&left, node *&right, int k ) {
	if( treap == NULL ) 
		left=right=NULL;
	else {
		if( size( treap->left ) < k ) {
			split( treap->right, treap->right, right, k - size( treap->left ) - 1 );
			left = treap;
		}
		else {
			split( treap->left, left, treap->left, k );
			right = treap;
		}
		treap->size = size( treap->left ) + size( treap->right ) + 1;
	}
}

/**
*	Une 2 treaps en uno solo.
*	El resultado queda guardado en el primer argumento.
*	O(log n) en promedio 
*/
void merge( node *&treap, node *left, node *right ) {
	if( left==NULL ) 
		treap=right;
	else if( right==NULL ) 
		treap=left;
	else {
		if( left->weight < right->weight ) {
			merge( left->right, left->right, right );
			treap = left;
		}
		else {
			merge( right->left, left, right->left );
			treap = right;
		}
		treap->size = size( treap->left) + size( treap->right ) + 1;
	}	
}

/**
*	Inserta un nuevo elemento en la k-ésima posición cuyo valor es c.
*	O(log n) en promedio
*/
void insert( node *&treap, int k, int v ) {
	node *left, *right;
	split( treap, left, right, k );
	merge( left, left, new node(v) );
	merge( treap, left, right);
}

/**
*	Elimina el k-ésimo elemento del árbol (o del arreglo).
*	O(log n) en promedio
*/
void del( node *&treap, int k) {
	node *left, *right, *dummy=NULL;
	split( treap, left,right,k);
	split( right, dummy, right,1);
	merge(treap, left, right);
}

/**
*	Regresa el elemento cuyo índice en el arreglo sería k.
*	O(log n) en promedio.
*/
node *search( node *treap, int k, int sum=0 ) {
	int index = sum + size( treap->left );
	if( index == k )
		return treap;
	else if( index > k ) 
		return search( treap->left, k, sum );
	else
		return search( treap->right, k, index + 1 );
}

inline int numsSize(node *treap) {
	if(treap == NULL)
		return 0;
	return (int)treap->nums.size();
}

inline pii numsVal(node *treap,int i) {
	if(treap == NULL || i>= treap->nums.size())
		return mp(oo,0);
	return mp(treap->nums[i], treap->freq[i]-(i==0?0:treap->freq[i-1]));
}

void combine(node *&treap) {
	vector<int> nums,freq;
	int curr_val=treap->value,curr_freq=1;
	bool bul=0;
	if(treap->left != NULL)
		combine(treap->left);
	if(treap->right != NULL)
		combine(treap->right);
	int i=0,j=0,lSize=numsSize(treap->left),rSize=numsSize(treap->right);
	while(i<lSize || j< rSize) {
		pii l=numsVal(treap->left,i),r=numsVal(treap->right,j),to_add;
		if(l.first == r.first) 
			to_add=mp(l.first,l.second+r.second),i++,j++;
		else if(l.first < r.first)
			to_add=l,i++;
		else
			to_add=r,j++;
		nums.pb(to_add.first),freq.pb(to_add.second);
		if(!bul && curr_val == nums[nums.size() -1])
			freq[freq.size()-1]+=curr_freq,bul=1;
		else if(!bul && curr_val < nums[nums.size() -1])
			swap(curr_val,nums[nums.size()-1]),swap(curr_freq,freq[freq.size()-1]);
	}
	if(!bul) {
		if(nums.empty() || curr_val != nums[nums.size() -1])
			nums.pb(curr_val),freq.pb(curr_freq);
		else
			freq[freq.size()-1]+=curr_freq;
	}
	for(int x=1;x<freq.size();x++)
		freq[x]+=freq[x-1];
	treap->nums=nums,treap->freq=freq;
}

/**
*	i: cota inferior del rango
*	j: cota superior del rango
*	k: numeros menores o iguales a k
*	sum: soporte para saber el indice
*/
int count(node *treap,int i,int j,int val,int sum=0) {
	int index = sum + size( treap->left );
	int res=0;
	int leftIndex= index - size( treap->left ), rightIndex= index + size( treap->right );
	if(i == leftIndex && j== rightIndex) {
		int inf=-1,sup=treap->nums.size()-1;
		while(sup-inf>1) {
			int m=inf+sup>>1;
			if(treap->nums[m] > val)
				sup=m;
			else
				inf=m;
		}
		if(treap->nums[sup]<=val)
			res+=treap->freq[sup];
		else if(inf>-1)
			res+=treap->freq[inf];
	}
	else if(index < i) 	//Buscar a la derecha
		res+=count(treap->right,i,j,val,index+1);
	else if(index > j) 	//Buscar a la izquierda
		res+=count(treap->left,i,j,val,sum);
	else {
		res+=treap->value <=val;
		if(i < index) 	//Dividir a la izquierda
			res+=count(treap->left,i,index-1,val,sum);
		if(index < j) 	//Dividir a la derecha
			res+=count(treap->right,index+1,j,val,index+1);
	}
	return res;
}

int main() {
	int n,t,k,x;
	node *treap=NULL;
	scanf("%d %d",&n,&t);
	for(x=0;x<n;x++) {
		scanf("%d",A+x);
		merge(treap,treap,new node(A[x]-x-1));
	}
	combine(treap);
	int ma=0;
	for(x=0;x<n;x++) if(A[x]<t){
		int j=min(n,t-max(0,(A[x]-x-1))-1)-1;
		int tmp=count(treap,0,j,A[x]-x-1);
		ma=max(ma,tmp);
	}
	printf("%d\n",ma);
	return 0;
}
