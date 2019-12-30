//https://codeforces.com/contest/1282/problem/A
#include<iostream>
using namespace std;
 
 
int f(int a,int b,int c,int d) {
	if(a<=c && c<=b) {
		if(d<=b) {
			return (b-a+1) - (d-c+1);
		}
		else {
			return c-a;
		}
	}
	else if(c<=a && a<=d) {
		if(b<=d) {
			return 0;
		}
		else {
			return b-d;
		}
	}
	return b-a;
}
 
int main() {
	int t,a,b,c,d,r;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d",&a,&b,&c,&r);
		printf("%d\n",f(min(a,b),max(a,b),c-r,c+r));
	}
	return 0;
}
