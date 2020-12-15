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
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll const oo = 1e9;
int const mod = 1e9 + 7;
int const N = 1e6 + 10;

bool B[N];

void sieve(int n) {
	B[1] = B[0] = 1;
	for(ll x = 2; x <= n; x ++) if(B[x] == 0) {
		B[x] = 0;
		for(ll y = x * x; y <= n; y += x) {
			B[y] = 1;
		}
	}
}

ll solve(string s, int i, int k) {
	if(i >= s.size()) {
		if(i == s.size() && k == 3) 
			return 1;
		else
			return oo;
	}
	
	ll ans = oo;
	fore(j, 1, s.size() - 3 + k - i + 1) {
		string num = s.substr(i, j);
		int n = stoi(num);
		
		if(B[n] == 0 && num[0] != '0') {
			// si n es primo
			ans = min(ans, n * solve(s, i + j, k + 1));
		}
	}
	return min(ans, oo);
}

int main() {
    FASTIO
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    sieve(N + 10);
    ll ans = oo;
    do {
    	ans = min(ans, solve(s, 0, 0));
    }while(next_permutation(s.begin(), s.end()));
    if(ans == oo) {
    	cout << "Bob lies\n";
    }
    else
    	cout << ans << endl;
    return 0;
}
