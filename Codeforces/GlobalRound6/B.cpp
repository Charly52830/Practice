//https://codeforces.com/contest/1266/problem/B
#include<iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	ll n;
	string res[]={"NO","YES"};
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<res[n>=15 && 1<= n%14 && n%14 <= 6]<<endl;
	}
	return 0;
}
