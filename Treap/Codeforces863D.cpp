//https://codeforces.com/contest/863/problem/D
#include <random>
#include <iostream>
#define MAX_INT (1LL<<31)-1
using namespace std;

int randInt() {
static random_device ran;
static mt19937 gen( ran() );
static uniform_int_distribution<> dis( 0 , MAX_INT );
return dis( gen );
}

struct node {
node *left, *right;
int weight, size;
int value;
bool reverse;

node( int v ) {
	left = right = NULL;
	weight = randInt();
	value = v;
	size = 1;
	reverse=0;
}

void lazyUpdate() {
	if(reverse) {
		if(left!=NULL)
			left->reverse=!(left->reverse);
		if(right!=NULL)
			right->reverse=!(right->reverse);
		swap(left,right);
		reverse=0;
	}
}
};

void print( node *treap ) {
if(treap != NULL) 
	treap->lazyUpdate();
else
	return;
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
if( treap != NULL)
	treap->lazyUpdate();
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
if(left != NULL)
	left->lazyUpdate();
if(right != NULL)
	right->lazyUpdate();
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
if(treap != NULL)
	treap->lazyUpdate();
int index = sum + size( treap->left );
if( index == k )
	return treap;
else if( index > k ) 
	return search( treap->left, k, sum );
else
	return search( treap->right, k, index + 1 );
}

void reverse(node *treap,int i,int j) {
node *left=NULL,*right=NULL,*mid=NULL;
split(treap,left,right,j+1);
split(left,left,mid,i);
mid->reverse=!mid->reverse;
merge(treap,left,mid);
merge(treap,treap,right);
}

void rotate(node *treap,int i,int j) {
node *left=NULL,*right=NULL,*mid=NULL;
split(treap,left,right,j+1);
split(left,left,mid,i);
node *last=NULL;
split(mid,mid,last,j-i);
merge(mid,last,mid);
merge(treap,left,mid);
merge(treap,treap,right);
}

int main() {
node *treap = NULL;
int n,q,m,x,k,a,b,c;
scanf("%d %d %d",&n,&q,&m);
for(x=0;x<n;x++) {
	scanf("%d",&k);
	merge(treap,treap,new node(k));
}
while(q--) {
	scanf("%d %d %d",&a,&b,&c);
	if(a==1) 
		rotate(treap,b-1,c-1);
	else 
		reverse(treap,b-1,c-1);
}
while(m--) {
	scanf("%d",&k);
	node *tmp=search(treap,k-1);
	printf("%d ",tmp->value);
}
printf("\n");
return 0;
}
