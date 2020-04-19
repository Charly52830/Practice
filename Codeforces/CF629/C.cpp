//https://codeforces.com/contest/1328/problem/C
#include<iostream>
using namespace std;
 
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		string a="1",b="1";
		int x;
		for(x=1;x<n && s[x] != '1'; x++) {
			if(s[x] == '0')
				a.push_back('0'), b.push_back('0');
			else
				a.push_back('1'),b.push_back('1');
		}
		if(x < n) {
			a.push_back('1'),b.push_back('0');
			for(x++;x<n;x++) {
				b.push_back(s[x]);
				a.push_back('0');
			}
		}		
		cout<<a<<endl<<b<<endl;
	}
	return 0;
}
