//https://codeforces.com/contest/1272/problem/E
#include<queue>
#include<vector>
#include<iostream>
#define N 200010
#define mp make_pair
using namespace std;
 
typedef pair<int,int> pii;
 
vector<int> v[N];
int A[N];
int res[N];
 
int main() {
	int n,x,k,k1,y;
	scanf("%d",&n);
	for(x=0;x<n;x++) 
		scanf("%d",A+x),res[x]=-1;
	queue<pii> q;
	for(x=0;x<n;x++) {
		k=x+A[x],k1=x-A[x];
		bool bul=0;
		if(k<n && (A[k]&1) != (A[x]&1)) 
			q.push(mp(x,1)),bul=1;
		else if(k<n)
			v[k].push_back(x);
		
		if(k1>=0 && (A[k1]&1) != (A[x]&1) && !bul) 
			q.push(mp(x,1));
		else if(k1>=0 && !bul)
			v[k1].push_back(x);
	}
	while(!q.empty()) {
		x=q.front().first,y=q.front().second;
		q.pop();
		if(res[x]!=-1)
			continue;
		res[x]=y;
		for(auto i:v[x]) 
			q.push(mp(i,y+1));
	}
	for(x=0;x<n;x++) 
		printf("%d ",res[x]);
	printf("\n");
	return 0;
}
