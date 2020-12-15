#include <math.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
int const oo = 1e9;
int const mod = 1e9 + 7;
int const N = 1000010;
 
vector<int> sieve(int n) {
	int lp[n + 1];
	vector<int> pr;
 
	for (int i=2; i<=n; ++i) {
		if (lp[i] == 0) {
		    lp[i] = i;
		    pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
		    lp[i * pr[j]] = pr[j];
	}
	return pr;
}
 
ll __pow(ll base, ll k) {
	ll ans = 1;
	while(k--) {
		ans *= base;
	}
	return ans;
}
 
int main() {
	FASTIO
	ll n, m;
	vector<int> primos = sieve(N);
	cin >> n >> m;
	vector<pii> v;
	for(int primo : primos) {
		int cnt = 0;
		while(m % primo == 0) {
			cnt ++;
			m/= primo;
		}
		if(cnt)
			v.pb({primo, cnt});
	}
	if(m > 1)
		v.pb({m, 1});
	
	ll ans = 1;
	for(auto &[primo, k] : v) {
		ans *= __pow(primo, k / n);
	}
	assert(ans >= 1);
	cout << ans << endl;
	return 0;
}
