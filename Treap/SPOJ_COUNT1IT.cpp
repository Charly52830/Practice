//https://www.spoj.com/problems/COUNT1IT/
#include<random>
#include<iostream>
#define MAX_INT 2147483647
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
	
	node(int v) {
		val=v;
		l=r=NULL;
		weight=randInt();
		size=1;
	}
	
};

inline int size(node *it) {
	return it?it->size:0;
}

int search(node *it,int val,int sum=0) {
	if(!it)
		return sum;
	int index=sum+size(it->l);
	if(val>=it->val) 
		return search(it->r,val,index+1);
	else 
		return search(it->l,val,sum);
}

void split(node *it,node *&left,node *&right,int i) {
	if(!it) 
		left=right=NULL;
	else {
		if(size(it->l)<i) {
			split(it->r,it->r,right,i-size(it->l)-1);
			left=it;
		}
		else {
			split(it->l,left,it->l,i);
			right=it;
		}
		it->size=size(it->l)+size(it->r)+1;
	}
}

void merge(node *&it,node *left,node *right) {
	if(!left) 
		it=right;
	else if(!right) 
		it=left;
	else {
		if(left->weight<right->weight) {
			merge(left->r,left->r,right);
			it=left;
		}
		else {
			merge(right->l,left,right->l);
			it=right;
		}
		it->size=size(it->l)+size(it->r)+1;
	}	
}

void insert(node *&treap,int val) {
	int index=search(treap,val);
	node *n=new node(val);
	node *left=NULL,*right=NULL;
	split(treap,left,right,index);	
	merge(left,left,n);
	merge(treap,left,right);
}

int get_val(node *treap,int i,int sum=0) {
	int index=sum+size(treap->l);
	if(index == i)
		return treap->val;
	else if(index < i)
		return get_val(treap->r,i,index+1);
	else
		return get_val(treap->l,i,sum);
}

int main() {
	node *treap=NULL;
	int n,q,x,k;
	scanf("%d %d",&n,&q);
	for(x=0;x<n;x++) {
		scanf("%d",&k);
		insert(treap,k);
	}
	while(q--) {
		scanf("%d %d",&x,&k);
		if(x==1) {
			int a=search(treap,k);
			insert(treap,k+a);
		}
		else if(x==2) 
			printf("%d\n",search(treap,k));
		else {
			if(k>size(treap))
				printf("invalid\n");
			else 
				printf("%d\n",get_val(treap,k-1));
		}		
	}
	return 0;
}
