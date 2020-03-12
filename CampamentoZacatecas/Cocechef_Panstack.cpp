//https://www.codechef.com/problems/PANSTACK
#include<iostream>
#define N 1010
#define mod 1000000007
using namespace std;

long long res[N];
long long dp[2][N];

int main() {
	for(int i = 1; i < N; i++) {
		dp[i&1][i - 1] = 0;
		for(int j = i;j < N; j++) {
			if(i == 1 && j == 1)
				dp[i&1][j] = 1;
			else
				dp[i&1][j] = ((dp[i & 1][j - 1] * i) % mod + dp[(i - 1) & 1][j - 1]) % mod;
			res[j] = (res[j] + dp[i&1][j]) % mod;
		}
	}
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("%d\n",(int)res[n]);
	}
	return 0;
}
