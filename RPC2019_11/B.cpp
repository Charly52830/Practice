//Carlos Ruvalcaba
//Equipo: #include<uaz>
#include<sstream>
#include<vector>
#include<iostream>
#define mod 1000000007
using namespace std;

typedef long long ll;

vector<string> v;
int x;

ll solve(bool bul) {
	ll res=(ll)bul;
	while(v[x][0]!=')') {
		if(v[x][0]=='(') {
			x++;
			if(bul)
				res=(res*solve(!bul))%mod;
			else
				res=(res+solve(!bul))%mod;
		}
		else {
			ll num=(ll)stoi(v[x]);
			num=num%mod;
			if(bul) 
				res=(res*num)%mod;
			else 
				res=(res+num)%mod;
			x++;
		}
	}
	x++;
	return res%mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	s+=" )";
	stringstream ss(s);
	while(ss>>s) 
		v.push_back(s);
	cout<<solve(0)<<endl;
	return 0;
}
