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
typedef pair<int, int> pii;

int const oo = 1e9;
ll const mod = 1e9 + 7;
int const N = 10010;

ll dp[2][N];

int main() {
	FASTIO
	int n, k, m;
	cin >> n >> k >> m;
	ll v = k;
	ll ans = 0;
	forn(j, n + 1) {
		for(int x = j - 1; x >= max(0, j - m); x --) 
			dp[(j & 1)][x] = 0;
		fore(i, j, n) {
			ll & _dp = dp[(j & 1)][i];
			// Casos base
			if(i == 0 || j == 0) {
				_dp = 0;
			}
			else if(j == 1 && i <= m) {
				_dp = 1;
			}
			else {
				int inf = max(i - m, 0);
				int sup = i - 1;
				if(inf)
					_dp = (dp[(j - 1) & 1][sup] - dp[(j - 1) & 1][inf - 1]) % mod;
				else
					_dp = dp[(j - 1) & 1][sup] % mod;
			}
			if(i > 0) 
				_dp = (_dp + dp[(j & 1)][i - 1]) % mod;
		}
		if(j > 0) {
			ll _dp = (dp[(j & 1)][n] - dp[(j & 1)][n - 1] + mod ) % mod;
			_dp = (_dp * v) % mod;
			ans = (ans + _dp) % mod;
			v = (v * (k - 1)) % mod;
		}
	}
	
	cout << ans << endl;
	return 0;
}
