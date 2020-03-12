//https://www.spoj.com/problems/BRKSTRNG/
#include<iostream>
#define N 1010
using namespace std;

typedef long long ll;

ll dp[N][N];
int pos[N][N];

int A[N];

int f(int i,int j) {
	if(!i) 
		return A[j];
	return A[j] - A[i-1];
}

int main() {
	int n,m,x,i,j;
	while(scanf("%d %d",&n,&m) != EOF) {
		for(x=0;x<m;x++) 
			scanf("%d",A+x);
		A[x]=n;
		// Knuth-Yao optimization O(n^2)
		for(int k=0;k<=m;k++) {
			for(i=0;i<=m-k;i++) {
				j=i+k;
				
				if(i == j) {
					dp[i][j] = 0;
					pos[i][j] = i;
				}
				else {
					int pos_left = pos[i][j-1];
					int pos_right = pos[i+1][j];
					int best_pos = pos_left;
					
					for(int p=pos_left + 1;p<=min(j-1,pos_right);p++) {
						if(dp[i][p] + dp[p+1][j] < dp[i][best_pos] + dp[best_pos + 1][j]) 
							best_pos = p;
					}
					dp[i][j] = dp[i][best_pos] + dp[best_pos + 1][j] + f(i,j);
					pos[i][j] = best_pos;
				}
			}
		}
		cout<<dp[0][m]<<endl;
	}
	return 0;
}
