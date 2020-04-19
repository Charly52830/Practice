//https://codeforces.com/contest/1333/problem/A
#include<iostream>
using namespace std;
 
char s[110];
 
int main() {
	int n,m;
	for(int x=0;x<110;x++) {
		s[x] = 'B';
	}
	int t;
	scanf("%d",&t);
	
	while(t--) {
		scanf("%d %d",&n,&m);
		s[0] = 'W';
		s[m] = '\0';
		printf("%s\n",s);
		s[0] = 'B';
		while(--n)
			printf("%s\n",s);
		s[m] = 'B';
	}
	return 0;
}
