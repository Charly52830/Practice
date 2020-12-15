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
int const mod = 1000000000 + 7;
int const N = 10005;

ll C[N + 10][N + 10];

void precal_comb(int n, int k) {
	C[0][0] = 1;
	fore(i, 1, n) {
		C[i][0] = 1;
		fore(j, 1, min(i, k) - 1) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
		C[i][i] = 1;
	}
	
	forn(i, n) {
		fore(j, 1, min(i, k)) {
			C[i][j] = (C[i][j - 1] + C[i][j] ) % mod;
		}
	}
}

int main() {
	FASTIO
	precal_comb(N, N);
	int t, a, n, b;
	cin >> t;
	while(t--) {
		cin >> n >> a >> b;
		cout << (C[n][b] - C[n][a - 1] + mod) % mod << endl;
	}
	return 0;
}
