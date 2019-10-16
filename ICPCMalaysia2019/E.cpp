//https://codeforces.com/gym/102219/problem/E
#include<iostream>
#define N 1010
using namespace std;

int T[60];
int dp[N][60],dp2[N][60];

int main() {
	int t,n,x,y;
	scanf("%d",&t);
	while(t) {
		scanf("%d",&n);
		for(x=n;x>0;x--)
			scanf("%d",T+x);
		for(x=0;x<=t;x++) {
			for(y=0;y<=n;y++) {
				if(!x)
					dp[x][y]=1;
				else if(x>0 && y<1)
					dp[x][y]=0;
				else if(T[y] > x) 
					dp[x][y]=dp[x][y-1],dp2[x][y]=dp2[x][y-1];
				else {
					if(dp[x-T[y]][y-1])
						dp[x][y]=1,dp2[x][y]=y;
					else if(dp[x][y-1])
						dp[x][y]=1,dp2[x][y]=dp2[x][y-1];
					else
						dp[x][y]=dp2[x][y]=0;
				}	
			}
		}
		int res=0;
		for(x=1;x<=t;x++) {
			if(dp[x][n])
				res=x;
		}
		x=res,y=dp2[x][n];
		while(x>0) {
			printf("%d ",T[y]);
			x-=T[y];
			y=dp2[x][y-1];
		}
		printf("%d\n",res);
		scanf("%d",&t);
	}	
	return 0;
}
