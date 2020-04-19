//https://codeforces.com/contest/1328/problem/E
#include<algorithm>
#include<iostream>
#include<vector>
#define N 200010
#define MAXLOG 19
using namespace std;
 
vector<int> v[N];
int P[N], depth[N];
int M[MAXLOG][N];
 
void dfs(int n,int d = 1) {
	depth[n] = d;
	M[0][n] = P[n];
	for(auto i:v[n]) {
		if(i != P[n]) {
			P[i] = n;
			dfs(i,d+1);
		}
	}
}
 
bool f(int a,int b) {
	return depth[a] < depth[b];
}
 
int kth_ancestor(int n,int k) { //k Ancestor	O(log n)
	for(int i=0;i<MAXLOG;i++)
		if(k&(1<<i))
			n=M[i][n];
	return n;
}
 
int main() {
	int n,q,x,a,b,m,y;
	scanf("%d %d",&n,&q);
	for(x=0;x<n-1;x++) {
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	
	M[0][1]=0;
	for(x=1;x<MAXLOG;x++) {
		for(y=1;y<=n;y++) {
			M[x][y]=M[x-1][M[x-1][y]];
		}
	}
	
	while(q--) {
		scanf("%d",&m);
		vector<int> A;
		for(x=0;x<m;x++) {
			scanf("%d",&a);
			A.push_back(a);
		}
		sort(A.begin(),A.end(),f);
		bool bul = 1;
		int last_depth = 1;
		int last_parent = 0;
		for(x=0;x<m && bul;x = y) {
			for(y = x; y < m && depth[A[x]] == depth[A[y]]; y++) {
				if(P[A[y]] != P[A[x]]) 
					bul = 0;
			}
			int kth = kth_ancestor(A[x], depth[A[x]] - last_depth );
			if(P[kth] != last_parent) {
				bul = 0;
				break;
			}
			last_depth = depth[A[x]];
			last_parent = P[A[x]];
		}
		if(bul)
			cout<<"YES\n";
		else
			cout<<"NO\n";		
	}
	return 0;
}
