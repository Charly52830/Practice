//http://coj.uci.cu/24h/problem.xhtml?pid=1083
#include<iostream>
#define N 1000010
using namespace std;

int dp[N];

int main() {
	int n,k,l,x;
	scanf("%d %d %d",&k,&l,&n);
	dp[0]=0;
	dp[1]=dp[k]=dp[l]=1;
	for(x=2;x<N;x++) {
		dp[x]|=!dp[x-1];
		if(x>k)
			dp[x]|=!dp[x-k];
		if(x>l)
			dp[x]|=!dp[x-l];
	}
	for(x=0;x<n;x++) {
		scanf("%d",&k);
		if(dp[k])
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
}
