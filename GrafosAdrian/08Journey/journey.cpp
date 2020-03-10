#include<cstdio>
#include<vector>
using namespace std;

int n;
bool visited [100000];
vector<vector<int>> adj;
double suma;

void dfs(int v,double longitud,double probabilidad){
	visited[v] = true;
	bool hoja = true;
	double brothers = 0;
	for(int u:adj[v]){
		if(!visited[u])
			brothers++;
	}
	
	for(int u:adj[v]){
		if(!visited[u]){
			dfs(u,longitud+1,probabilidad/brothers);
			hoja = false;
		}
	}
	
	if(hoja){
		suma+=longitud*	probabilidad;
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
	dfs(0,0.0,1);
	double resultado = suma;
	printf("%.10lf\n",resultado);
	return 0;
}

