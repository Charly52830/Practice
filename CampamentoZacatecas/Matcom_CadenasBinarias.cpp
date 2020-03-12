//https://matcomgrader.com/problem/9516/cadenas-binarias/
#include<iostream>
#define N 110
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

pii A[N];
int dp[2][N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,U,C,x;
	string s;
	cin>>C>>U>>n;
	for(x=0;x<n;x++) {
		cin>>s;
		int u=0,c=0;
		for(auto i:s) {
			u+= i=='1';
			c+= i=='0';
		}
		A[x]=mp(c,u);
	}
	for(int i=n-1;i>=0;i--) {
		for(int c=0;c<=C;c++) {
			for(int u=0;u<=U;u++) {
				dp[i&1][c][u]=dp[(i+1)&1][c][u];
				if(c>=A[i].first && u>= A[i].second) 
					dp[i&1][c][u]=max(dp[(i+1)&1][c-A[i].first][u-A[i].second] + 1, dp[i&1][c][u] );
			}
		}
	}
	cout<<dp[0][C][U]<<endl;
	return 0;
}
