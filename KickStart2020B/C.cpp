//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
#include<set>
#include<iostream>
#define MOD 1000000000LL
using namespace std;

typedef long long ll;

class Vector {
	
	public:
	
	ll x,y;
	
	Vector() {
		x = 0LL;
		y = 0LL;
	}
	
	Vector(ll x, ll y) : x(x), y(y) {}
	
	void operator+=(const Vector &V) {
		x = (x + V.x + MOD) % MOD;
		y = (y + V.y + MOD) % MOD;
	}
	
	Vector operator*(const ll &S) {
		x = (x * S + MOD) % MOD;
		y = (y * S + MOD) % MOD;
		Vector ans(x,y);
		return ans;
	}
	
};

ll X[]={-1,0,1,0};
ll Y[]={0,-1,0,1};
set<char> dir={'N','W','S','E'};
int C[256];

int i;
Vector f(string &s) {
	Vector cur(0,0);
	ll mul=0;
	for(;s[i] != ')';i++) {
		if(dir.count(s[i])) {
			cur.x = (cur.x + X[C[s[i]]] + MOD) % MOD;
			cur.y = (cur.y + Y[C[s[i]]] + MOD) % MOD;
		}
		else if(s[i] == '(') {
			i++;
			cur += f(s) * mul;
			mul = 0;
			i--;
		}
		else {	// Número
			mul = mul * 10LL + ((ll)(s[i] - '0'));
		}
	}
	i++;
	return cur;
}

int main() {
	C['N'] = 0;
	C['W'] = 1;
	C['S'] = 2;
	C['E'] = 3;
	int t,T;
	string s;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin>>s;
		Vector origin(1,1);
		i=0;
		s = s + ")";
		origin += f(s);
		if(origin.x == 0)
			origin.x = MOD;
		if(origin.y == 0)
			origin.y = MOD;
		cout<<"Case #"<<t<<": "<<origin.y<<" "<<origin.x<<endl;
	}
	return 0;
}
