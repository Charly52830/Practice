#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int main(){
	int n,m;
	vector<int> side;
	queue<int> q;
	bool is_bipartite = true;
	vector<int> s0;
	vector<int> s1;
	
	scanf("%d %d",&n,&m);
	
	vector<vector<int>> adj;
	
	for(int i = 0;i<n;i++){
		side.push_back(-1);
	}
	
	for(int i = 0;i<n;i++){
		vector<int> aux;
		adj.push_back(aux);
	}
	
	for(int i = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	
	for (int st = 0; st < n; ++st) {
		if (side[st] == -1) {
			side[st] = 0;
			int adyacentes = adj[st].size();
			if(adyacentes != 0){
				q.push(st);
				s0.push_back(st);
			}
			
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : adj[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
						if(side[u] == 0){
							s0.push_back(u);
						}else{
							s1.push_back(u);
						}
					} else {
						if(side[u]==side[v]){
							printf("-1\n");
							return 0;
						}
						
					}
				}
			}
		}    
	}
	
	int len0 = s0.size();
	int len1 = s1.size();
	printf("%d\n",len0);
	for(int v:s0)
		printf("%d ",v+1);
	printf("\n%d\n",len1);
	for(int v:s1)
		printf("%d ",v+1);
	printf("\n");
	return 0;
}
