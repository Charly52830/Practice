////https://codeforces.com/contest/1333/problem/C
#include<queue>
#include<map>
#include<iostream>
#define mp make_pair
#define key first
#define val second
#define N 200010
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q; 
 
map<ll,queue<int> > mapa;
int A[N];
 
int main() {
	int n,g,m=-1;
	ll sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",A+i);
		sum+=A[i], mapa[sum].push(i);
	}
	ll ans=0;
	sum=0;
	for(int i=0;i<n;i++) {
		sum-=A[i];
		ll k=-(A[i] + sum);
		while(!mapa[k].empty() && mapa[k].front() < i)
			mapa[k].pop();
		if(!mapa[k].empty()) g=mapa[k].front();
		else g=n;
		q.push(mp(g,i));
		while(!q.empty() && q.top().key == i)
			m=max(m,q.top().val),q.pop();
		ans+=i-m;
	}
	cout<<ans<<endl;
	return 0;
}
