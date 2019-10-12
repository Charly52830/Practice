#include<vector>
#include<iostream>
#define N 100010
using namespace std;

typedef long long ll;

vector<int> v[N];
ll A[N],depth[N];

void dfs(int n,int p,ll d=0) {
	depth[n]=d;
	for(auto i:v[n]) if(i!=p)
		dfs(i,n,d+1);
}

int main() {
	int n,x,a,b,k;
	scanf("%d",&n);
	for(x=1;x<=n;x++) {
		scanf("%d",&k);
		A[x]=(ll)k;
		A[x]=A[x]/2;
	}
	for(x=1;x<n;x++) {
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,1);
	ll res=0;
	for(x=1;x<=n;x++) {
		if(A[x]&1)
			res^=depth[x];
	}
	if(res)
		printf("Gana el primer jugador.\n");
	else
		printf("Gana el segundo jugador.\n");	
	return 0;
}
