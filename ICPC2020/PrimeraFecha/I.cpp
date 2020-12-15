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

string S=".#$%/(&)";

bool mayus(string s) {
	bool bul = 0;
	for(char c : s) {
		bul |= 'A' <= c && c <= 'Z';
	}
	return bul;
}

bool napa(string s) {
	bool bul = 0;
	for(char c : s) {
		bul |= 'a' <= c && c <= 'z';
	}
	return bul;
}

bool is_digit(char c) {
	return '0' <= c && c <= '9';
}

bool digits(string s) {
	bool cons = 0;
	bool digit = 0;
	forn(i, s.size()) {
		digit |= is_digit(s[i]);
		if(i > 0 && is_digit(s[i]) && is_digit(s[i - 1]) && abs(s[i] - s[i - 1]) == 1)
			cons = 1;
	}
	return digit & (!cons);
}

bool special(string s) {
	bool bul = 0;
	for(char c : s) {
		for(char k : S) {
			bul |= c == k;
		}
	}
	return bul;
}

int main() {
    FASTIO
    int T;
    string s;
    
    string A[]={
    	"Rejected",
    	"Rejected",
    	"Rejected",
    	"Weak",
    	"Good",
    	"Strong"
    };
    
    cin>>T;
    fore(t, 1, T) {
    	cin>>s;
    	int ans = 0;
    	ans += mayus(s);
    	ans += napa(s);
    	ans += digits(s);
    	ans += special(s);
    	ans += s.size() >= 10;
    	cout << "Assertion number #" << t << ": " << A[ans] << endl;
    }
    return 0;
}
