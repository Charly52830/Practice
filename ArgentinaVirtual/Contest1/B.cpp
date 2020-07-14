//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/B
#include<iostream>
using namespace std;
typedef long long ll;
int M;
const int MAXN = 250010;
 
ll F[MAXN];
 
int main() {
	int n;
	cin>>n>>M;
	F[0] = 1; 
	for(int i = 1; i < MAXN; i++)
		F[i] = F[i-1]*i %M;
	
	ll ans = 0;
	for(ll L = 1; L <= n; L++) {
		ll k = (n - L + 1);
		ans = (ans + k * k % M * F[L] % M * F[n - L] % M) % M;
	}
	cout<<ans<<endl;
	return 0;
}
