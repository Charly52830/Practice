//https://codeforces.com/contest/1335/problem/B
#include<iostream>
#define N 2010
using namespace std;
 
char ans[N];
 
int main() {
	int t,n,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&a,&b);
		for(int x=0;x<n;x++) {
			ans[x] = (char)(x % b) + 'a';
		}
		ans[n] = '\0';
		printf("%s\n",ans);
	}
	return 0;	
}
