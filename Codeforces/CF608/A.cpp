//https://codeforces.com/contest/1271/problem/A
#include<iostream>
using namespace std;
 
typedef long long ll;
 
ll f(int a,int b,int c,int d,int e,int f1) {
	ll k=min(a,d);
	ll F1=f1;
	d-=k;
	return k*e + min(min(b,c),d)*F1;
}	
 
ll F(int a,int b,int c,int d,int e,int f1) {
	ll k=min(min(b,c),d);
	ll F1=f1;
	ll E=e;
	d-=k;
	return k*F1 + min(a,d)*E;
}
 
int main() {
	int a,b,c,d,e,g;
	cin>>a>>b>>c>>d>>e>>g;
	cout<<max(f(a,b,c,d,e,g),F(a,b,c,d,e,g))<<endl;
	return 0;
}
