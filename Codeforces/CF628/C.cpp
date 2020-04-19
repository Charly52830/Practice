//https://codeforces.com/contest/1325/problem/C
#include<string.h>
#include<vector>
#include<iostream>
#define N 100010
#define mp make_pair
using namespace std;
 
typedef pair<int,int> pii;
 
vector<pii> v[N];
int res[N];
 
int main() {
	int n,a,b,c;
	scanf("%d",&n);
	memset(res,-1,sizeof res);
	for(int x=0;x<n-1;x++) {
		scanf("%d %d",&a,&b);
		v[a].push_back(mp(b,x));
		v[b].push_back(mp(a,x));
	}
	bool bul=0;
	for(int x=1;x<=n;x++) {
		if(!bul && v[x].size() >=3) {
			a=v[x][0].second;
			b=v[x][1].second;
			c=v[x][2].second;
			res[a]=0;
			res[b]=1;
			res[c]=2;
			bul=1;
		}
	}
	int j;
	if(bul) 
		j=3;
	else 
		j=0;
	for(int x=0;x<n-1;x++)
		if(res[x] == -1) {
			res[x]=j++;
		}
	for(int x=0;x<n-1;x++) {
		printf("%d\n",res[x]);
	}
	return 0;
}
