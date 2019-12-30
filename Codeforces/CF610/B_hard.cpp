//https://codeforces.com/contest/1282/problem/B2
#include<algorithm>
#include<iostream>
#define N 200010
using namespace std;
 
int A[N];
 
int main() {
	int t,n,p,k,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&p,&k);
		for(x=0;x<n;x++) 
			scanf("%d",A+x);
		sort(A,A+n);
		int res=0;
		for(x=0;x<n;x++) {
			if(x==0 || x==k-1) 
				x=x;
			else if(x>0 && x<k-1) 
				A[x]+=A[x-1];
			else 
				A[x]+=A[x-k];
			if(A[x]<=p)
				res=x+1;
		}
		printf("%d\n",res);
	}
	return 0;
}
