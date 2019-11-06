#include<algorithm>
#include<iostream>
#define N 1000010
#define oo 1000000000010LL
using namespace std;

typedef long long ll;

int n,k;
int A[N];

ll f(ll i) {
	ll sum=0,K=k;
	for(int x=0;x<n;x++,i+=K) {
		ll tmp=A[x];
		sum+=abs(tmp-i);
	}
	return sum;
}

int main() {
	int x;
	scanf("%d %d",&n,&k);
	for(x=0;x<n;x++)
		scanf("%d",A+x);
	sort(A,A+x);
	ll inf=-oo,sup=oo;
	while(inf<sup) {
		ll m=inf+sup>>1;
		if(f(m+1)<=f(m))
			inf=m+1;
		else
			sup=m;
	}
	cout<<f(inf)<<endl;
	return 0;
}
