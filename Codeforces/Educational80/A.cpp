//https://codeforces.com/contest/1288/problem/A
#include<iostream>
using namespace std;
 
int func(int d,int m) {
	return d/(m+1) + !!(d%(m+1)) + m;
}
 
int main() {
	int t,n,d;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&d);
		//Ternary search
		int i=1,f=d;
		while(f-i > 120) {
			int a=(2*i + f)/3, b=(i + 2*f)/3;
			if(func(d,a) < func(d,b)) 
				f=b;
			else
				i=a;
		}
		bool bul=0;
		for(int x=i;x<=f;x++) 
			bul|=func(d,x) <= n;
		if(bul)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

