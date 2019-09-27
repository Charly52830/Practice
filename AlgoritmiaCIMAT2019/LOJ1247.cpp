//https://vjudge.net/problem/LightOJ-1247
#include<iostream>
using namespace std;

typedef long long ll;

int main() {
	int t,x,n,m,y,k;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d %d",&n,&m);
		ll res=0;
		for(x=0;x<n;x++) {
			ll sum=0;
			for(y=0;y<m;y++)
				scanf("%d",&k),sum+=k;
			res^=sum;
		}
		if(res)
			printf("Case %d: Alice\n",i);
		else
			printf("Case %d: Bob\n",i);
	}
	return 0;
}
