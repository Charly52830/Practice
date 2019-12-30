//https://codeforces.com/contest/1283/problem/E
#include<algorithm>
#include<set>
#include<iostream>
#define N 200010
using namespace std;
 
set<int> s,s2;
 
int A[N],dp[N],B[N];
 
int main() {
	int n,x,m=0;
	scanf("%d",&n);
	for(x=0;x<n;x++) {
		scanf("%d",A+x);
		s.insert(A[x]);
	}
	sort(A,A+n);
	//Min
	for(auto i:s) 
		B[m++]=i;
	for(x=m-1;x>=0;x--) {
		dp[x]=1;
		if(B[x+2]-B[x] == 2 && B[x+2]-B[x+1] == 1) {
			int k=min(dp[x+2],dp[x+3]);
			dp[x]+=min(k,dp[x+1]);
		}
		else if(B[x+1]-B[x] <= 2) 
			dp[x]+=min(dp[x+1],dp[x+2]);
		else
			dp[x]+=dp[x+1];
	}
	//Max
	int sum=0;
	for(x=0;x<n;x++) {
		if(!s2.count(A[x]-1)) {
			sum++;
			s2.insert(A[x]-1);
		}
		else if(!s2.count(A[x])) {
			sum++;
			s2.insert(A[x]);
		}
		else if(!s2.count(A[x]+1)) {
			sum++;
			s2.insert(A[x]+1);
		}
	}
	printf("%d %d\n",dp[0],sum);
	return 0;
}
