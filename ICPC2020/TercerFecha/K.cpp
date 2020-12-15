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
#define forr(i,a,b) for(int i=a;i<b;i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int const oo = 1e9;
int const mod = 1e9 + 7;

const int MAXN = 300010;

ll M = 1e9 + 7;
ll *INV;
ll F[MAXN], FI[MAXN];

/* Precomputo de inverso modular para responder en O(1) */
void precal_invmod() {
	INV = (ll*)malloc(MAXN * sizeof(ll));
	INV[1] = 1; forr(i, 2, MAXN) INV[i] = M - (ll)(M / i) * INV[M % i] % M;
}

/* Precomputo de factoriales y su inverso multiplicativo */
void precal_fact() {
	F[0] = 1; forr(i, 1, MAXN) F[i] = F[i - 1] * i % M;
	if(!INV) precal_invmod();
	FI[0] = 1; forr(i, 1, MAXN) FI[i] = FI[i - 1] * INV[i] % M;
}

/* Coeficientes binomiales con factoriales pre calculados*/
ll Comb(ll n, ll k) {
	if(n < k) return 0;
	return F[n] * FI[k] % M * FI[n - k] % M;
}

int main() {
	FASTIO
	precal_fact();
	int t, A, B, C, k, d;
	
	cin>> t;
	while(t--) {
		cin >> A >> B >> C >> k >> d;
		ll ans;
		if(d > C || k > A + B + C ||  k - d < 2 || k - d > A + B) {
			ans = 0;
			cout << ans << endl;
		}
		else {		
			ll ans = (Comb(A + B, k - d) - Comb(A, k - d) + M) % M;
			ans = (ans - Comb(B, k - d) + M ) % M;
			ans = (ans * Comb(C, d)) % M;
			cout << ans << endl;
		}
	}
	return 0;
}
