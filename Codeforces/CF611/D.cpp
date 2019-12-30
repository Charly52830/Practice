//https://codeforces.com/contest/1283/problem/D
#include<set>
#include<map>
#include<queue>
#include<iostream>
#define mp make_pair
#define oo 1000000010
#define N 200010
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
priority_queue<pii,vector<pii>,greater<pii> > q1,q2;
map<int,int> mapa;
set<int> s;
int res[N];
 
int main() {
	int n,m,x,k,a,b,r=0;
	scanf("%d %d",&n,&m);
	for(x=0;x<n;x++) {
		scanf("%d",&k);
		s.insert(k);
	}
	for(int k:s) {
		mapa[k]=max(mapa[k],oo);
		if(!mapa.count(k+1) && !s.count(k+1))
			mapa[k+1]=1, q1.push(mp(1,k+1));
		if(!mapa.count(k-1))
			mapa[k-1]=1, q2.push(mp(1,k-1));
	}
	ll sum=0;
	while(m--) {
		if(q1.top().first < q2.top().first) {
			a=q1.top().first, b=q1.top().second;
			q1.pop();
			sum+=a,res[r++]=b;
			if(!mapa.count(b+1)) 
				q1.push(mp(a+1,b+1)), mapa[b+1]=a+1;
		}
		else {
			a=q2.top().first, b=q2.top().second;
			q2.pop();
			sum+=a,res[r++]=b;
			if(!mapa.count(b-1)) 
				q2.push(mp(a+1,b-1)), mapa[b-1]=a+1;
		}
	}
	cout<<sum<<endl;
	for(x=0;x<r;x++)
		cout<<res[x]<<" ";
	cout<<endl;
	return 0;
}
