//https://codeforces.com/contest/1288/problem/C
#include<iostream>
#define mod 1000000007
#define N 1010
using namespace std;
 
typedef long long ll;
 
ll dp[2][N];
 
int main() {
	int n,m,i,a;
	scanf("%d %d",&n,&m);
	for(i=m-1;i>=0;i--) {
		for(a=1;a<=n;a++) {
			dp[i&1][a]=dp[i&1][a-1];
			if(i==m-1) 
				dp[i&1][a]= (dp[i&1][a] + a)%mod;
			else {
				for(int j=0;j<a;j++) 
					dp[i&1][a]=  (dp[i&1][a] + dp[(i+1)&1][a-j])%mod;
			}
			
		}
	}
	cout<<dp[0][n]<<endl;
	return 0;
}
