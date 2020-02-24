//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3613
#include<string.h>
#include<map>
#include<iostream>
#define N 1010
using namespace std;

typedef long long ll;

ll dp[2][N],dp2[2][N];
int A[N],B[N];
int TA[N],TB[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,k;
	string s;
	cin>>t;
	while(t--)  {
		map<string,int> nombres;
		k=0;
		cin>>n;
		for(int x=1;x<=n;x++) {
			cin>>s>>s>>A[x];
			if(!nombres.count(s)) 
				nombres[s]=k++;
			TA[x]=nombres[s];
		}
		cin>>m;
		for(int x=1;x<=m;x++) {
			cin>>s>>s>>B[x];
			if(!nombres.count(s)) 
				nombres[s]=k++;
			TB[x]=nombres[s];			
		}
		memset(dp,0,sizeof dp);
		memset(dp2,0,sizeof dp2);
		for(int i=1;i<=n;i++) {
			dp[i&1][0]=0;
			for(int j=1;j<=m;j++) {
				if(dp[(i-1)&1][j] == dp[i&1][j-1]) {
					dp[i&1][j]=dp[i&1][j-1];
					dp2[i&1][j]=min(dp2[(i-1)&1][j],dp2[i&1][j-1]);
				}
				else if(dp[(i-1)&1][j] > dp[i&1][j-1]){
					dp[i&1][j]=dp[(i-1)&1][j];
					dp2[i&1][j]=dp2[(i-1)&1][j];
				}
				else {
					dp[i&1][j]=dp[i&1][j-1];
					dp2[i&1][j]=dp2[i&1][j-1];
				}
				if(TA[i] == TB[j]) {
					if(A[i] + B[j] + dp[(i-1)&1][j-1] == dp[i&1][j]) 
						dp2[i&1][j] = min(dp2[i&1][j], 1 + dp2[(i-1)&1][j-1]);
					else if(A[i] + B[j] + dp[(i-1)&1][j-1] > dp[i&1][j]) {
						dp[i&1][j]=A[i] + B[j] + dp[(i-1)&1][j-1];
						dp2[i&1][j]= 1 + dp2[(i-1)&1][j-1];
					}
				}
				
			}
		}
		cout<<dp[n&1][m]<<" "<<dp2[n&1][m]<<endl;
	}
	return 0;
}
