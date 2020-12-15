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

int const oo = 1e9;
int const mod = 1e9 + 7;

int main() {
    FASTIO
    int n;
    cin>>n;
    vector<pii> v;
    forn(i,n) {
    	int a;
    	cin>>a;
    	v.pb({a, i});
    }
    sort(v.begin(), v.end());
    map<int,vector<int>> mapa;
    for(auto [a, b] : v) {
    	mapa[a].pb(b);
    }
    
    int index = n, ans = 0;
    
    fore(i, 1, v.size() - 1) {
    	int a = v[i].F, b = v[i].S;
    	int a_1 = v[i - 1].F;
    	if(mapa.count(a_1)) {
    		vector<int> A = mapa[a_1];
			vector<int>::iterator it = lower_bound(A.begin(), A.end(), b);
			
			if(it != A.end()) {
				// Se encontró una nueva solución
				index = i;
				int last_index = A[A.size() - 1];
				vector<int> B = mapa[a];
				vector<int>::iterator it2 = lower_bound(B.begin(), B.end(), last_index);
				if(it2 == B.end())
					ans = 0;
				else
					ans = B.end() - it2;
				break;
			}
    	}
    }
    
    cout << n - index - ans << endl; 
    return 0;
}
