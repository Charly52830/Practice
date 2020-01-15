//https://codeforces.com/contest/1288/problem/B
#include<iostream>
using namespace std;
 
typedef long long ll;
 
string f(int x) {
	string res="";
	while(x--)
		res.push_back('9');
	return res;
}
 
int main() {
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		int l=to_string(b).size();
		ll k=l-1+ (f(l) == to_string(b));
		cout<<k*a<<endl;
	}
	return 0;
}
