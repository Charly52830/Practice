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
int const N = 2e5+10;

map<int,map<int,int>> mapa;
int max_index[N], max_sum[N];
bool multiple[N];

int max_global;
int i_global, j_global;
bool multiple_global;

int main() {
	FASTIO
	int n, q;
	cin>>n>>q;
	while(q--) {
		char c;
		int a, b;
		cin >> c;
		if(c == 'R') {
			cin >> a >> b;
			mapa[a][b] ++;
			if(!max_index[a]) {
				max_index[a] = b;
				max_sum[a] = 1;
			}
			else if(mapa[a][b] >= max_sum[a]) {
				if(mapa[a][b] == max_sum[a]) {
					// Un nuevo número empató al mayor
					multiple[a] = true;
				}
				else {
					// Un nuevo número superó al mayor
					multiple[a] = false;
					max_index[a] = b;
					max_sum[a] = mapa[a][b];
				}
			}
			
			if(!max_global) {
				max_global = 1;
				i_global = a;
				j_global = b;
			}
			else if(mapa[a][b] >= max_global) {
				if(mapa[a][b] == max_global) {
					// Un nuevo par empató al par mayor
					multiple_global = true;
				}
				else {
					// Un nuevo par superó al par mayor
					multiple_global = false;
					max_global = mapa[a][b];
					i_global = a;
					j_global = b;
				}
			}
			
		}
		else if(c == 'Q') {
			cin >> a;
			if(!max_index[a]) {
				cout << "No info\n";
			}
			else if(multiple[a]) {
				cout << "Multiple\n";
			}
			else {
				cout << max_index[a] << endl;
			}
		}
		else {
			if(!max_global) {
				cout << "No info\n";
			}
			else if(multiple_global) {
				cout << "Multiple\n";
			}
			else {
				cout << i_global << " " << j_global << endl;
			}
		}
	}
	return 0;
}
