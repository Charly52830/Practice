//https://www.codechef.com/problems/PPTEST
#include<string.h>
#include<iostream>
#define N 110
using namespace std;

int A[N];
int P[N];
int dp[N];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,x,W,a,b;
		scanf("%d %d",&n,&W);
		for(x=0;x<n;x++) {
			scanf("%d %d %d",&a,&b,A+x);
			P[x]=a*b;
		}
		memset(dp,0,sizeof dp);
		for(int i=n-1;i>=0;i--) {
			for(int w=W;w>=A[i];w--) 
				dp[w]=max(dp[w],dp[w-A[i]] + P[i]);
		}
		cout<<dp[W]<<endl;
	}
	
	return 0;
}
