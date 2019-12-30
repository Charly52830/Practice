//https://codeforces.com/contest/1271/problem/B
#include<vector>
#include<iostream>
#define oo 1000000010
using namespace std;
 
typedef pair<bool,vector<int> > pbv;
 
char A[256];
 
pbv f(string s) {
	vector<int> v;
	int x;
	for(x=0;x<s.size()-1;x++) {
		if(s[x] == 'W') {
			s[x]=A[s[x]];
			s[x+1]=A[s[x+1]];
			v.push_back(x+1);
		}
	}
	if(s[x] == 'W')
		return make_pair(0,v);
	else
		return make_pair(1,v);
}
 
int main() {
	A['B']='W';
	A['W']='B';
	string s;
	int n;
	cin>>n>>s;
	pbv res1=f(s);
	for(int x=0;x<s.size();x++) 
		s[x]=A[s[x]];
	pbv res2=f(s);
	if(res1.first || res2.first) {
		if(res1.first) {
			cout<<res1.second.size()<<endl;
			for(auto i:res1.second)
				cout<<i<<" ";
			cout<<endl;
		}
		else {
			cout<<res2.second.size()<<endl;
			for(auto i:res2.second)
				cout<<i<<" ";
			cout<<endl;
		}
	}
	else
		cout<<-1<<endl;
	return 0;
}
