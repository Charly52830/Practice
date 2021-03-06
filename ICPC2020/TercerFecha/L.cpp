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

int main() {
	FASTIO
	int t;
	cin >> t;
	set<string> _set;
	int ans = 0;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		s += s;
		bool nuevo = 1;
		forn(i, n) {
			string ss = s.substr(i, n);
			if(_set.count(ss))
				nuevo = 0;
		}
		ans += nuevo;
		
		_set.insert(s.substr(0, n));
	}
	cout << ans << endl;
	return 0;
}
