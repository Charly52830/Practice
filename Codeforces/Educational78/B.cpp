//https://codeforces.com/contest/1278/problem/B
#include<math.h>
#include<iostream>
using namespace std;
 
typedef long long ll;
 
int f(int z) {
	ll Z=z;
	double k=sqrt(8*Z+1);
	int K=k;
	return (K-1)/2;
}
 
int F(int z) {
	ll Z=z;
	return (int)(Z*(Z+1))/2;
}
 
int main() {
	int t,n,a,b,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		n=abs(a-b),k=f(n);
		int q=n-F(k),res;
		if(q==0) 
			res=k;
		else if(k&1 && q&1) 
			res=k+2;
		else if(k&1 && !(q&1))
			res=k+1;
		else if(!(k&1) && q&1) 
			res=k+1;
		else 
			res=k+3;
		printf("%d\n",res);
	}
	return 0;
}
