#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj;
int n;
int t;
int visited [30001];

void dfs(int actual){
	visited[actual] = 1;
	if(actual<n-1)
		dfs(adj[actual]+actual);
}

int main(){
	scanf("%d %d",&n,&t);
	t--;
	for(int i = 0;i<n-1;i++){
		int aux;
		scanf("%d",&aux);
		adj.push_back(aux);
	}
	
	dfs(0);
	
	if(visited[t])
		printf("YES\n");
	else
		printf("NO\n");
		
		
	return 0;
}
