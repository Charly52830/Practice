//https://codeforces.com/contest/1277/problem/A
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
 
int main() {
	vector<int> v;
	string s="123456789";
	for(char c : s) {
		string num="";
		int t=9;
		while(t--) {
			num.push_back(c);
			v.push_back(stoi(num));
		}
	}
	sort(v.begin(),v.end());
	v.push_back(1000000001);
	int t,n,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(x=0;x<v.size() && v[x]<=n;x++);
		printf("%d\n",x);
	}
	return 0;
}
