//https://codeforces.com/contest/1279/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,a,b,c;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&a,&b,&c);
		if(a-b-c <= 1 && b-c-a <=1 && c-a-b <=1) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
