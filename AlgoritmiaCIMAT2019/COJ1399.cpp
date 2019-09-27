//http://coj.uci.cu/24h/problem.xhtml?pid=1399
#include<iostream>
#define N 110
using namespace std;

int dp[N][N][N];

int main() {
	int x,y,z;
	for(x=0;x<N;x++) {
		for(y=0;y<N;y++) {
			for(z=0;z<N;z++) {
				
				if(x==0 && y==0 && z==0)	
					continue;
				
				if(x>=1)
					dp[x][y][z]|=!dp[x-1][y][z];
				if(y>=1)
					dp[x][y][z]|=!dp[x][y-1][z];
				if(y>=2)
					dp[x][y][z]|=!dp[x][y-2][z];
				if(z>=1)
					dp[x][y][z]|=!dp[x][y][z-1];
				if(z>=2)
					dp[x][y][z]|=!dp[x][y][z-2];
				if(z>=3)
					dp[x][y][z]|=!dp[x][y][z-3];
				dp[x][y][z]|=!dp[x-(x>0)][y-(y>0)][z-(z>0)];
			}
		}
	}
	scanf("%d %d %d",&x,&y,&z);
	while(x||y||z) {
		if(dp[x][y][z])
			printf("%d %d %d Bilbo wins\n",x,y,z);
		else
			printf("%d %d %d Frodo wins\n",x,y,z);
		scanf("%d %d %d",&x,&y,&z);
	}
	return 0;
}
