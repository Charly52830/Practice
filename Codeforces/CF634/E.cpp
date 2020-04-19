//https://codeforces.com/contest/1335/problem/E
#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define N 200010
using namespace std;
 
int A[N];
 
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		forn(i,n) cin>>A[i];
		vector<vector<int>> v(200, vector<int>(n + 1));
		vector<int> pos[200];
		forn(j, n) {
			forn(i, 200) v[i][j + 1] = v[i][j] + (A[j] - 1 == i);
			pos[A[j] - 1].pb(j);
		}		
		int ans = 0;
		forn(i, 200) {
			ans = max(ans, sz(pos[i]));
			forn(j, sz(pos[i]) / 2) {
				int l = pos[i][j] + 1, r = pos[i][sz(pos[i]) - j - 1];
				forn(x, 200) ans = max(ans, (v[x][r] - v[x][l]) + (j + 1) * 2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
