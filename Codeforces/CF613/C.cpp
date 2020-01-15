//https://codeforces.com/contest/1285/problem/C
#include<iostream>
using namespace std;
 
typedef long long ll;
 
ll gcd(ll a,ll b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
 
int main() {
	ll n,res=1,x;
	cin>>n;
	for(x=1;x*x<n;x++) if(n%x == 0 && gcd(x,n/x) == 1)
		res=x;
	cout<<res<<" "<<n/res<<endl;
	return 0;
}
