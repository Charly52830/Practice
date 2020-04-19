//https://codeforces.com/contest/1330/problem/A
#include<string.h>
#include<iostream>
#define N 210
using namespace std;
 
int A[N];
 
int main() {
	int n,x,t,k;
	cin>>t;
	while(t--) {
		memset(A,0,sizeof A);
		cin>>n>>x;
		for(int i=0;i<n;i++) {
			scanf("%d",&k);
			A[k] = 1;
		}
		int i;
		for(i=1;x || A[i];i++) {
			if(!A[i]) 
				x--;
		}
		printf("%d\n",i-1);
	}
		
	return 0;
}
