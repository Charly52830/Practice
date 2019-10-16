//https://codeforces.com/gym/102219/problem/K
#include<algorithm>
#include<iostream>
#define N 100010
using namespace std;

typedef long long ll;

int A[N];

int main() {
	int n,t,x;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&n);
		for(x=0;x<n;x++)
			scanf("%d",A+x);
		sort(A,A+n);
		int res=0;
		ll sum=0;
		for(x=0;x<n;x++) {
			if(sum<=A[x]) 
				res++,sum+=A[x];
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}
