#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> adj;
int n;
int visited [1001];


void dfs(int v){
	visited[v] = 1;
	for(int u: adj[v]){
		if(!visited[u]){
			dfs(u);
		}else{
			printf("%d ",u+1);
			return;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int blame;
		scanf("%d",&blame);
		blame--;
		vector<int> aux;
		aux.push_back(blame);
		adj.push_back(aux);
	}
	
	for(int i = 0;i<n;i++){
		memset(visited,0,sizeof(visited));
		dfs(i);
	}
	printf("\n");
	return 0;
}

//https://codeforces.com/problemset/problem/1020/B
