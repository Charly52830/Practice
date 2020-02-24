//https://codeforces.com/contest/1311/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		if(a>b) {
			if((a-b)%2 == 0)
				printf("1\n");
			else
				printf("2\n");
		}
		else if(a<b) {
			if((b-a)%2 == 0)
				printf("2\n");
			else
				printf("1\n");
		}
		else
			printf("0\n");
	}
	return 0;
}

