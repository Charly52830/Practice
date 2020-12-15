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
int const mod = 1e9 + 7;
int const N = 50;

int n,m;

char v[N][N];
int B[N][N];

void hor(int x, int y, string & S, int bitmask) {
	string s = "";
	int sz = S.size();
	fore(i, y, y + sz - 1) {
		if(i < m) {
			s.pb(v[x][i]);
		}
	}
	sort(s.begin(), s.end());
	if(s != S) 
		return;
	fore(i, y, y + sz - 1) {
		B[x][i] |= bitmask;
	}
}

void ver(int x, int y, string & S, int bitmask) {
	string s = "";
	int sz = S.size();
	fore(i, x, x + sz - 1) {
		if(i < n)
			s.pb(v[i][y]);
	}
	sort(s.begin(), s.end());
	if(s != S) 
		return;
	
	fore(i, x, x + sz - 1) {
		B[i][y] |= bitmask;
	}
}

void diag1(int x, int y, string & S, int bitmask) {
	string s = "";
	int sz = S.size();
	forn(i, sz) {
		if(x + i < n && y + i < m)
			s.pb(v[x + i][y + i]);
	}
	sort(s.begin(), s.end());
	if(s != S) 
		return;
	forn(i, sz) {
		if(x + i < n && y + i < m)
			B[x + i][y + i] |= bitmask;
	}
	
}

void diag2(int x, int y, string & S, int bitmask) {
	string s = "";
	int sz = S.size();
	forn(i, sz) {
		if(x + i < n && y - i >= 0)
			s.pb(v[x + i][y - i]);
	}
	sort(s.begin(), s.end());
	if(s != S) 
		return;
	forn(i, sz) {
		if(x + i < n && y - i >= 0)
			B[x + i][y - i] |= bitmask;
	}
}

int count_zeros(int o) {	
	int sum = 0;
	while(o) {
		o -= o & -o;
		sum ++;
	}
	
	return sum > 1;
}

int main() {
	FASTIO
	int k;
	cin>>n>>m;
	forn(i, n) {
		forn(j, m) {
			cin >> v[i][j];
		}
	}
	cin >> k;
	forn(i, k) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		forn(x, n) {
			forn(y, m) {
				hor(x, y, s, 1<<i);
				ver(x, y, s, 1<<i);
				diag1(x, y, s, 1<<i);
				diag2(x, y, s, 1<<i);
			}
		}
	}
	
	int ans = 0;
	forn(i, n) {
		forn(j, m) {
			ans += count_zeros(B[i][j]);
			//cout << B[i][j] << " ";
		}
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}
