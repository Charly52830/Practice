#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int,int>> pares [2500];

int distancia(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	//Inicializando dp
	int dp[50][50];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			dp[i][j]= 10000000;
		}
	}
	
	
	for(int curr = 0;curr<n;curr++){
		for(int curc = 0;curc<n;curc++){
			int x;
			scanf("%d",&x);
			pares[x].push_back(make_pair(curr,curc));
		}
	}
	
	//Inicializando el primer numero
	for(int i = 0;i<pares[1].size();i++){
		int cr = pares[1][i].first;
		int cc = pares[1][i].second;
		dp[cr][cc] = 0;
	}
	
	for(int i = 0;i<=k;i++){
		for(int j  =0 ;j<pares[i].size();j++){
			int cr = pares[i][j].first;
			int cc = pares[i][j].second;
			for(int l = 0;l<pares[i-1].size();l++){
				int crl = pares[i-1][l].first;
				int ccl = pares[i-1][l].second;
				dp[cr][cc] =  min(dp[cr][cc],dp[crl][ccl]+distancia(cc,cr,ccl,crl));
			}
		}
	}
	/*
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	
	int minimo = 10000000;
	for(int i = 0;i<pares[k].size();i++){
		int cr = pares[k][i].first;
		int cc = pares[k][i].second;
		//printf("%d\n",dp[cr][cc]);
		minimo = min(minimo,dp[cr][cc]);
	}
	
	if(minimo == 10000000){
		printf("-1\n");
		return 0;
	}else{
		printf("%d\n",minimo);
	}		
}
