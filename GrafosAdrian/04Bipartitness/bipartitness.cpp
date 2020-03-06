#include <cstdio>
#include <vector>
using namespace std;

int n;
long long bi[2];
vector<vector<int>> adj;
bool visited [1000001];

void dfs(int v,int b){
	visited[v] = true;
	bi[b%2]++;
	for(int u: adj[v]){
		if(!visited[u]){
			
			dfs(u,b+1);
			
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		vector<int> aux;
		adj.push_back(aux);
	}
	
	for(int i = 0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	long long result = (bi[0]*bi[1])-(n-1);
	printf("%lld\n",result);
	return 0;
}

//https://codeforces.com/problemset/problem/862/B
