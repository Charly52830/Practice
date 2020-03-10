#include<cstdio>
#include<vector>
#include<set>
using namespace std;

int n;
vector<vector<int>> adj;
vector<set<int>> adjSet;
vector<int> comp;
bool visited[150000];

void dfs(int v){
	visited[v] = true;
	comp.push_back(v);
	for(int u: adj[v]){
		if(!visited[u])
			dfs(u);
	}
}


vector<vector<int>> find_comps(){
	vector<vector<int>> x;
	for(int i = 0;i<n;i++){
		if(!visited[i]){
			comp.clear();
			dfs(i);
			x.push_back(comp);
		}
	}
	return x;
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		vector<int> aux;
		set<int> aux2;
		adj.push_back(aux);
		adjSet.push_back(aux2);
	}
	
	for(int i = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
		adjSet[x-1].insert(y-1);
		adjSet[y-1].insert(x-1);
	}
	
	vector<vector<int>> cc = find_comps();
	
	
	for(int i = 0;i<cc.size();i++){
		if(cc[i].size()>2){
			for(int u =0;u<cc[i].size()-1;u++){
				for(int v = u+1;v<cc[i].size();v++){
					int x = cc[i][u];
					int y = cc[i][v];
					if(adjSet[x].find(y)==adjSet[x].end() && adjSet[y].find(x)==adjSet[y].end()){
						printf("NO\n");
						return 0;
					}
				}
			}
		}
	}
	printf("YES\n");
	return 0;
	
}
