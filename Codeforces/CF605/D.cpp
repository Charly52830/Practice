//https://codeforces.com/contest/1272/problem/D
#include<iostream>
#define N 200010
using namespace std;
 
int A[N],B[N],C[N];
 
int main() {
	int n,x;
	scanf("%d",&n);
	for(x=0;x<n;x++)
		scanf("%d",A+x);	
	*B=C[n-1]=1;
	int res=0;
	for(x=1;x<n;x++) 
		B[x]=1 + B[x-1]*(A[x-1]<A[x]),res=max(res,B[x]);
	for(x=n-1;x>=0;x--) {
		C[x]=1 + C[x+1]*(A[x+1] > A[x]);
		res=max(res,C[x]);
	}
	for(x=1;x<n-1;x++) if(A[x+1] > A[x-1]) {
		res=max(res,B[x-1]+C[x+1]);
	}
	cout<<res<<endl;
	return 0;
}
