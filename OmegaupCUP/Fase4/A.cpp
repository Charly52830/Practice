//https://omegaup.com/arena/omegacup4/#problems/atsa-copa-fut
#include<iostream>
using namespace std;

typedef long long ll;

ll A[1010];

int main() {
	int n,k;
	cin>>n;
	for(int x=0;x<n;x++) cin>>k,A[k]++;
	ll ans=0;
	for(ll x=1;x<=1000;x++) {
		for(ll y=x;y<=1000;y++) {
			if(x==y)
				ans+=(A[x]*(A[x] - 1LL))/2LL * x*x;
			else
				ans+=x*y*A[x]*A[y];
		}
	}
	cout<<ans<<endl;
	return 0;
}
