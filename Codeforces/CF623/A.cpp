//https://codeforces.com/contest/1315/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,a,b,x,y;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d",&a,&b,&x,&y);
		printf("%d\n",max(max(x*b,(a-x-1)*b),max(y*a,(b-y-1)*a)));
		
	}
	return 0;
}
