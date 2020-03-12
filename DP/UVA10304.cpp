//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245
#include<iostream>
#define N 260
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

ll f2(int i,int j,int p) {
	ll res=0;
	if(p == i) 
		return dp[i+1][j];
	else if(p == j) 
		return dp[i][j-1];
	return dp[i][p-1] + dp[p+1][j];
}

int main() {
	int n,x,i,j;
	while(scanf("%d",&n) != EOF) {
		for(x=0;x<n;x++) {
			scanf("%d",A+x);
			if(x)
				A[x]+=A[x-1];
		}
		// Knuth-Yao optimization
		for(int k=0;k<n;k++) {
			for(i=0;i<n-k;i++) {
				j=i+k;
				
				if(i == j) {
					dp[i][j] = f(i,i);
					pos[i][j] = i;
				}
				else {
					
					int pos_left = pos[i][j-1];
					int pos_right = pos[i+1][j];
					int best_pos = pos_left;
					
					for(int p=pos_left + 1;p<=pos_right;p++) {
						if(f2(i,j,p) < f2(i,j,best_pos))
							best_pos = p;
					}
					dp[i][j] = f2(i,j,best_pos) + f(i,j);
					pos[i][j] = best_pos;
				}
			}
		}
		cout<<dp[0][n-1] - f(0,n-1) <<endl;
	}
	return 0;
}
