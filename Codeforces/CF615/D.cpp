//https://codeforces.com/contest/1294/problem/D
#include<iostream>
#define N 400010
using namespace std;
 
int A[N];
 
int main() {
	int q,x,k;
	scanf("%d %d",&q,&x);
	int mex=0;
	while(q--) {
		scanf("%d",&k);
		A[k%x]++;
		while(A[mex%x] > 0) {
			A[mex%x]--;
			mex++;
		}
		printf("%d\n",mex);
	}
	return 0;
}

