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

int M[20][20];

bool test_c(int l, int r, int c) {
	bool bul = 1;
	fore(i,c, c + l - 1) {
		bul &= M[r][i] == 0;
		M[r][i] = 1;
	}
	return bul;
}

bool test_r(int l, int r, int c) {
	bool bul = 1;
	fore(i, r, r + l - 1) {
		bul &= M[i][c] == 0;
		M[i][c] = 1;
	}
	return bul;
}

int main() {
	FASTIO
	int b, l, d, r, c;
	cin>>b;
	bool bul = true;
	while(b--) {
		cin >> d >> l >> r >> c;
		if(!d) {
			bul &= 1 <= c && c + l - 1 <= 10;
			bul &= test_c(l, r, c);
		}
		else {
			bul &= 1 <= r && r + l - 1 <= 10;
			bul &= test_r(l, r, c);
		}
	}
	if(bul)
		cout << "Y\n";
	else
		cout << "N\n";
	return 0;
}
