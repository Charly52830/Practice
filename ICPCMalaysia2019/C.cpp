//https://codeforces.com/gym/102219/problem/C
#include<iostream>
#define oo 1000000010
using namespace std;

int main() {
	int t,n,s,f,T,x;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d %d",&n,&s);
		int res=-oo;
		for(x=0;x<n;x++) {
			scanf("%d %d",&f,&T);
			if(T<=s)
				res=max(res,f);
			else 
				res=max(res, f-(T-s) );
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}
