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
