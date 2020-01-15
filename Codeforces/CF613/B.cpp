//https://codeforces.com/contest/1285/problem/B
#include<iostream>
#define N 200010
#define oo 1000000010
using namespace std;
 
typedef long long ll;
 
int A[N];
 
int main() {
	int n,t,x;
	ll k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ll sum=0,dp=-oo,max_dp=dp;
		for(x=0;x<n;x++) {
			scanf("%d",A+x);
			sum+=A[x];
		}
		for(x=0;x<n-1;x++) {
			k=A[x];
			dp=max(k,dp+k);
			max_dp=max(max_dp,dp);
		}
		dp=-oo;
		for(x=1;x<n;x++) {
			k=A[x];
			dp=max(k,dp+k);
			max_dp=max(max_dp,dp);
		}
		if(sum>max_dp)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
