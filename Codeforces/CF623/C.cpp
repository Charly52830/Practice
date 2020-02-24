//https://codeforces.com/contest/1315/problem/C
#include<string.h>
#include<queue>
#include<iostream>
#define N 210
using namespace std;
 
int A[N];
int C[N];
 
int main() {
	int t,n,x,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		memset(C,0,sizeof C);
		for(x=1;x<=n;x++) {
			scanf("%d",&k);
			A[2*x-1]=k;
			C[k]=2*x-1;
		}
		for(x=1;x<=2*n;x+=2) {
			int y;
			for(y=A[x]+1;C[y] && y<=2*n;y++);
			if(!C[y]) {
				A[x+1]=y;
				C[y]=x+1;
			}
		}
		bool bul=0;
		for(x=1;x<=2*n;x++)
			bul|=!C[x];
		if(bul) {
			printf("-1\n");
		}
		else {
			for(x=1;x<=2*n;x++) {
				printf("%d ",A[x]);
			}
			printf("\n");
		}
	}
	return 0;
}

