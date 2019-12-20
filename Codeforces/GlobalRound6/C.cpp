//https://codeforces.com/contest/1266/problem/C
#include<iostream>
using namespace std;
 
int main() {
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	if(n==1 && m==1) {
		printf("0\n");
		return 0;
	}
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			if(m>=n) 
				printf("%d ",(x+1)*(n+m-y));
			else
				printf("%d ",(n+m-x)*(y+1));
		}			
		printf("\n");
	}
	return 0;
}
