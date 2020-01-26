//https://codeforces.com/contest/1294/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,a,b,c,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d",&a,&b,&c,&n);
		int m=max(a,b);
		m=max(m,c);
		int s=(m-a) + (m-b) + (m-c);
		bool bul=0;
		if(s > n) {
			printf("NO\n");
			continue;
		}
		n-=s;
		if(n % 3 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
