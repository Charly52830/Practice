//https://vjudge.net/problem/LightOJ-1186
#include<iostream>
#define N 210
using namespace std;

int A[N];

int main() {
	int t,n,x,k;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		int res=0;
		scanf("%d",&n);
		for(x=0;x<n;x++)
			scanf("%d",A+x);
		for(x=0;x<n;x++) 
			scanf("%d",&k),res^=k-A[x]-1;
		if(res)
			printf("Case %d: white wins\n",i);
		else
			printf("Case %d: black wins\n",i);
	}
	return 0;
}
