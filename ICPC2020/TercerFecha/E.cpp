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
const int N = 100010;

int main() {
	FASTIO
	ll n, b;
	cin >> n >> b;
	vector<ll> v(n), ans(n, 1), C(n, 0);
	for(ll & i : v)
		cin >> i;
	queue<int> q;
	forn(i, n) {
		if(v[(i + 1) % n] > v[i])
			C[(i + 1) % n] ++;
		if(v[(i - 1 + n) % n] > v[i])
			C[(i - 1 + n) % n] ++;
	}
	
	forn(i, n) {
		if(C[i] == 0) {
			q.push(i);
			if(v[i] == 0)
				ans[i] = 0;
		}		
	}
	
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		if(v[(i + 1) % n] > v[i]) {
			ans[(i + 1) % n] = max(ans[i] + 1, ans[(i + 1) % n]);
			C[(i + 1) % n] --;
			
			if(C[(i + 1) % n] == 0)
				q.push((i + 1) % n);
		}
		
		if(v[(i - 1 + n) % n] > v[i]) {
			ans[(i - 1 + n) % n] = max(ans[(i - 1 + n) % n], ans[i] + 1);
			C[(i - 1 + n) % n] --;
			
			if(C[(i - 1 + n) % n] == 0)
				q.push((i - 1 + n) % n);
		}
	}
	
	cout << ans[0] * b;
	fore(i,1, n - 1) {
		cout << " " << ans[i] * b;
	}
	cout << endl;
	
	return 0;
}
