//https://vjudge.net/problem/LightOJ-1192
#include<iostream>
using namespace std;

int main() {
	int t,x,n,a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%d",&n);
		int res=0;
		for(x=0;x<n;x++) 
			scanf("%d %d",&a,&b),res^=b-a-1;
		if(res)
			printf("Case %d: Alice\n",i+1);
		else
			printf("Case %d: Bob\n",i+1);
	}
	return 0;
}
