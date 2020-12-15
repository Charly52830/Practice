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
const int N = 30;

int n, g;
int suma_objetivo;
int total;
int A[N];

set<int> ans;

int contar_unos(int k) {
	int ans = 0;
	while(k) {
		k -= k & -k;
		ans ++;
	}
	return ans;
}

int max_unos = N;

void backtracking(int i, int bitmask, int sum) {
	// Ver si la suma ya da para ya no continuar
	if(sum >= suma_objetivo) {
		int unos = contar_unos(bitmask);
		if(unos < max_unos) {
			max_unos = unos;
			//ans.resize(0);
			set<int> _set;
			swap(ans, _set);
		}
		if(unos == max_unos)
			//ans.pb(bitmask);
			ans.insert(bitmask);
		return;
	}
	else if(i >= n)
		return;
	
	// Sumar A_i
	backtracking(i + 1, bitmask | (1 << i), sum + A[i]);
	
	// No sumar A_i
	backtracking(i + 1, bitmask, sum);
}

int main() {
	FASTIO
	scanf("%d %d", &n, &g);
	forn(i, n) {
		scanf("%d", A + i);
		total += A[i];
	}
	suma_objetivo = total * g / 100;
	if((total * g) % 100 > 0)
		suma_objetivo ++;
	
	int bitmask = 0;
	backtracking(0, bitmask, 0);
	
	printf("%d %d\n", max_unos, int(ans.size()));
	for(auto i : ans) {
		int sum = 0;
		forn(j, n) {
			if(i & (1<<j)) {
				sum += A[j];
			}
		}
		printf("%d", sum * 100 / total);
		forn(j, n) {
			if(i & (1<<j)) {
				printf(" %d", j + 1);
			}
		}
		printf("\n");
	}
	return 0;
}
