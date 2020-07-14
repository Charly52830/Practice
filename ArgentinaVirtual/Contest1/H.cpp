//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/H
#include<iostream>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int MAXN = 1010;
 
ll F[MAXN], FI[MAXN], INV[MAXN];
 
ll Comb(ll n, ll k) {
	if(n < k) return 0;
	return F[n]*FI[k] % M * FI[n - k] % M;	
}
 
int main() {
	F[0] = 1; 
	for(int i = 1; i < MAXN; i++)
		F[i] = F[i-1]*i %M;
	INV[1] = 1;
	for(int i = 2; i < MAXN; i++)
		INV[i] = M - (ll)(M / i)* INV[M % i] % M;
	FI[0] = 1;
	for(int i = 1; i < MAXN; i++)
		FI[i] = FI[i - 1] * INV[i] % M;
	
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans = Comb(n - 1, 2 * k) * Comb(m - 1, 2 * k) % M;
	cout<<ans<<endl;
	return 0;
}

