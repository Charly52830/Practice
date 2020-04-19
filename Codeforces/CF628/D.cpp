//https://codeforces.com/contest/1325/problem/D
#include<iostream>
using namespace std;
 
typedef long long ll;
 
 
 
int main() {
	ll b,n;
	cin>>b>>n;
	if(b == 0 && n == 0) 
		cout<<0<<endl;
	else if(b == n) 
		cout<<1<<endl<<b<<endl;
	else if(b>n || (n - b) % 2 == 1) 
		cout<<-1<<endl;
	else {
		ll k=(n-b)/2;
		if(((k+b) ^ k) == b) 
			cout<<2<<endl<<k+b<<" "<<k<<endl;
		else
			cout<<3<<endl<<k<<" "<<k<<" "<<b<<endl;
	}
	return 0;
}
