//https://codeforces.com/contest/1337/problem/C
#include<queue>
#include<vector>
#include<iostream>
#define N 200010
#define pb push_back
#define mp make_pair
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> pli;
 
vector<int> v[N];
ll tam[N],P[N],depth[N],color[N];
priority_queue<pli> q;
 
int dfs(int n,int p=1, int d=0) {
	P[n] = p;
	tam[n] = 1;
	depth[n] = d;
	for(auto i:v[n]) if(i != p){
		tam[n] += dfs(i,n,d+1);
	}
	return tam[n];
}
 
ll ans = 0;
ll dfs_res(int n) {
	ll t = !color[n];
	for(auto i:v[n]) if(i != P[n]) {
		t += dfs_res(i);
	}
	if(color[n]) 
		ans += t;
	return t;
}
 
int main() {
	int n,k,a,b;
	scanf("%d %d",&n,&k);
	for(int x=1;x<n;x++) {
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1);
	k=n-k;
	q.push(mp(0,1));
	while(k--) {
		ll key=q.top().first;
		int x=q.top().second;
		q.pop();
		color[x] = 1;
		for(auto i:v[x]) if(i != P[x]) {
			q.push(mp((tam[i] - 1LL) * (depth[i] + 1LL) - tam[i] * depth[i],i));
		}
	}
	dfs_res(1);
	cout<<ans<<endl;
	return 0;
}

