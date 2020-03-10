#include<cstdio>
#include<iostream>
#include<sstream>
#include<vector>
#include<set>
using namespace std;


int n;
vector<vector<int>> adj;
vector<set<int>> conjuntos;
bool visited[500001];

void dfs(int i,int begin,int j){
	visited[i] = true;
	conjuntos[j].insert(i);
	for(int u: adj[i]){
		if(!visited[u]){
			dfs(u,begin,j);
		}
	}
}


int main(){
	int m;
	scanf("%d %d\n",&n,&m);
	for(int i = 0;i<n;i++){
		vector<int> aux;
		adj.push_back(aux);
	}
	
	for(int i = 0;i<m;i++){
		char line[3500000];
		cin.getline(line,3500000);
		string linea(line);
		istringstream ss(linea);
		string tok;
		getline(ss,tok,' ');
		if(tok  == "1")
			getline(ss,tok,' ');
		
		string anterior;
		getline(ss,anterior,' ');
		while(getline(ss,tok,' ')){
			int x = stoi(anterior);
			int y = stoi(tok);
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
			anterior = tok;
		}
		
	}

	int j = -1;
	for(int i = 0;i<n;i++){
		if(!visited[i]){
			set<int> aux;
			conjuntos.push_back(aux);
			j++;
			dfs(i,i,j);
		}
	}
	
	int resultado[n];
	for(int i = 0;i<conjuntos.size();i++){
		set<int> aux = conjuntos[i];
		for (auto it=aux.begin(); it != aux.end(); ++it){
			int x = aux.size();
			resultado[*it] = x;
		}
	}
	
	for(int i = 0;i<n;i++){
		printf("%d ",resultado[i]);
	}
	printf("\n");
	return 0;
}

