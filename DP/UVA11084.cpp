//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2025
#include<string.h>
#include<map>
#include<iostream>
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

char s[20];
int d,n;
map<pii,int> dp;

int M[11][12];

int dfs(int bitmask, int r) {
	if(!dp.count(mp(bitmask,r))) {
		int A[10];
		memset(A,-1,sizeof A);
		int y=0;
		for(int x=0;x<n;x++) {
			if(bitmask & (1<<x)) 
				A[s[x]-'0'] = x;
			else
				y++;
		}
		for(int x=0;x<10;x++) {
			if(A[x]!=-1) 
				dp[mp(bitmask,r)] += dfs( bitmask & ~ (1<<(A[x])) , (r - M[x][y] + d) % d);
		}
	}
	return dp[mp(bitmask,r)];
}

int main() {
	int t,x,y;
	scanf("%d",&t);
	while(t--) {
		scanf("%s %d",s,&d);
		n = strlen(s);
		map<pii,int> tmp;
		swap(tmp,dp);
		dp[mp(0,0)] = 1;
		for(x=0;x<10;x++) {
			M[x][0] = x % d;
			for(y=1;y<11;y++) 
				M[x][y] = (M[x][y - 1] * 10) % d;
		}
		printf("%d\n",dfs((1<<n) - 1, 0) );
	}
	return 0;
}
