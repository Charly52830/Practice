//https://codeforces.com/gym/102219/problem/B
#include<iostream>
using namespace std;

int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		if(n==m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
