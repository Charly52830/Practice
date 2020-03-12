//https://matcomgrader.com/problem/9519/buscando-palabras/
#include<iostream>
#define N 2010
using namespace std;

int dp[2][N];

int main() {
	int n,m;
	cin>>n>>m;
	string s,p;
	cin>>s>>p;
	s = "$"+s;
	p = "$"+p;
	dp[0][0]=1;
	for(int i=1;i<p.size() && p[i] == '*';i++)
		dp[0][i] = 1;
	for(int i=1;i<s.size();i++) {
		for(int j=1;j<p.size();j++) {
			dp[i&1][j] = 0;
			if(p[j] == s[i]) 
				dp[i&1][j]|=dp[(i-1)&1][j-1];
			else if(p[j] == '?') 
				dp[i&1][j]|=dp[(i-1)&1][j-1];
			else if(p[j] == '*') 
				dp[i&1][j] |= dp[(i - 1) & 1][j] | dp[i & 1][j - 1];
		}	
	}
	n=s.size() - 1;
	m = p.size() -1;
	if(dp[n&1][m])
		cout<<"SI\n";
	else
		cout<<"NO\n";
	return 0;
}
