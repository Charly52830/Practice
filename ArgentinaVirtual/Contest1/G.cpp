//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/G
#include<vector>
#include<iostream>
#define N 100010
using namespace std;
 
vector<int> v[N];
 
int ans, global_depth = 0;
void dfs(int n, int depth, int p) {
	if(depth > global_depth)
		ans = n, global_depth = depth;
	for(auto i:v[n]) if(i != p) 
		dfs(i, depth + 1, n);
}
 
vector<int> A;
int source, sink;
bool bul = 1;
int root;
 
void dfs2(int n, int p) {
	A.push_back(n);
	if(n == sink) {
		bul &= A.size() & 1;
		root = A[A.size() / 2];
	}
	for(auto i:v[n]) if(i != p) {
		dfs2(i, n);
	}
	A.pop_back();
}
 
 
int last_depth = -1;
void dfs3(int n, int p,int depht = 0) {
	for(auto i:v[n]) if(i != p) {
		dfs3(i, n, depht + 1);
	}
	if(v[n].size() == 1) {	// Hoja
		if(last_depth == -1)
			last_depth = depht;
		else
			bul &= depht ==last_depth;
	}
	else {
		if(n == root)
			bul &= v[n].size() >= 3;
		else
			bul &= v[n].size() >= 4;
	}
}
 
int main() {
	int n,k,a,b;
	scanf("%d %d",&n,&k);
	for(int x = 0; x < n - 1; x++) {
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0, 1);
	source = ans;
	global_depth = 0;
	dfs(source, 0, source);
	sink = ans;
	int length = global_depth;
	dfs2(source, source);
	bul &= length == 2 * k;
	dfs3(root, root);
	if(bul) {
		cout<<"Yes\n";
	}
	else
		cout<<"No\n";
	return 0;
}

