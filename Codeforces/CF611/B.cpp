//https://codeforces.com/contest/1283/problem/B
#include<iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
	int t;
	ll n,k;
	scanf("%d",&t);
	while(t--) {
		cin>>n>>k;
		cout<<(k*(n/k) + min(n%k,k/2) )<<endl;
	}
	return 0;
}
