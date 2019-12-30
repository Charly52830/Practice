//https://codeforces.com/contest/1270/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,n,a,b,x,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&a,&b);
		int m1=0,m2=0;
		for(x=0;x<a;x++) {
			scanf("%d",&k);
			m1=max(m1,k);
		}
		for(x=0;x<b;x++) {
			scanf("%d",&k);
			m2=max(m2,k);
		}
		if(m1>m2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

