#include<cstdio>
#include<vector>
using namespace std;	

int n;
vector<vector<int>> adj;
vector<int> comp;
bool visited[2000000];

void dfs(int v){
	visited[v] = true;
	comp.push_back(v);
	for(int u:adj[v]){
		if(!visited[u])
			dfs(u);
	}
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		vector<int> aux;
		adj.push_back(aux);
	}
	
	for(int i = 0 ;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	
	int cycles = 0;
	for(int i = 0;i<n;i++){
		if(!visited[i]){
			comp.clear();
			dfs(i);
			bool cy = true;
			for(int i = 0;i<comp.size();i++){
				if(adj[comp[i]].size()!=2){
					cy = false;
					break;
				}
			}
			if(cy)
				cycles++;
		}
	}
	
	printf("%d\n",cycles);
	return 0;
}
