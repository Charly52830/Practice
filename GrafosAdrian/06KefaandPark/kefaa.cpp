#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int n;
int max_p;

bool cats[500000];
bool visited[500000];

int dfs(int v, int power){
	visited[v] = true;
	if(cats[v])
		power--;
	else 
		power = max_p;
	
	bool hoja = true;
	for(int u:adj[v]){
		if(!visited[u])
			hoja = false;
	}	
	
	if(power>=0 && !hoja){
		int suma = 0;
		for(int u:adj[v])
			if(!visited[u])
				suma+= dfs(u,power);
		return suma;
	}else if(power<0){
		return 0;
	}else if(hoja)
		return 1;
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	max_p = m;
	for(int i = 0;i<n;i++){
		vector<int> aux;
		adj.push_back(aux);
	}
	for(int i = 0;i<n;i++){
		int aux;
		scanf("%d",&aux);
		cats[i] = aux;
	}
	
	for(int i = 0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	printf("%d\n",dfs(0,m));
}
