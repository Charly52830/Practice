//https://codeforces.com/contest/1294/problem/E
#include<vector>
#include<map>
#include<iostream>
using namespace std;
 
int f(vector<int> v,int c,int m,int M) {
	int n=v.size(),res=n;
	map<int,int> mapa;
	for(int i = 0;i<v.size();i++) {
		if(v[i]%m != c%m || v[i] > M) 
			continue;
		int index = v[i]/m - (!c);
		int dif;
		if(i >= index)
			dif = i-index;
		else
			dif=abs(i-(index-n));
		mapa[dif]++;
	}
	for(auto j:mapa) 
		res = min(res, j.first + (n - j.second) );
	return res;
}
 
vector<vector<int> > M1;
 
int main() {
	int n,m,x,y,k;
	scanf("%d %d",&n,&m);
	M1.resize(n);
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			scanf("%d",&k);
			M1[x].push_back(k);
		}
	}
	int res=0;
	for(x=0;x<m;x++) {
		vector<int> v;
		for(y=0;y<n;y++)
			v.push_back(M1[y][x]);
		res+=f(v,(x+1)%m,m,n*m);
	}
	cout<<res<<endl;
	return 0;
}
