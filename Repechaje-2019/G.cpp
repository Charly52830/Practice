//https://www.juezguapa.com/problemas/enunciado/guarding-the-museum
//Status: WA :(
#include<queue>
#include<vector>
#include<iostream>
#define N 100010
#define root 1
#define oo 1000000010
using namespace std;

typedef long long ll;

int F[N],G[N],H[N],P[N];
int A[N];
vector<int> v[N];

bool is_leaf(int n) {
	return v[n].size() == 1 && n != root;
}

void dfs(int n,int p=root) {
	P[n]=p;
	for(auto i:v[n]) if(i!=p) 
		dfs(i,n);
}

int main() {
	int n,c,x,a,b;
	scanf("%d %d",&n,&c);
	for(x=0;x<n-1;x++) {
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(root);
	//Toposort
	queue<int> q;
	for(x=1;x<=n;x++) {
		if(is_leaf(x))
			q.push(x);
		else
			A[x]=v[x].size()-1 + (x==root);
	}
	while(!q.empty()) {
		x=q.front();
		q.pop();
		//Calcular H
		H[x]=oo;
		int sum=0,c=oo;
		for(auto i:v[x]) if(i!=P[x]) {
			sum+=min(F[i],H[i]);
			if(F[i]>=H[i])
				c=min(c,F[i]-H[i]);
			else
				c=0;
		}
		H[x]=min(H[x],sum+c);
		
		//Calcular G
		G[x]=0;
		if(!is_leaf(x)) {
			for(auto i:v[x]) if(i!=P[x]) 
				G[x]+=min(F[i],H[i]);
		}
		
		//Calcular F
		F[x]=1;
		if(!is_leaf(x)) {
			for(auto i:v[x]) if(i!=P[x]) 
				F[x]+=min(F[i],G[i]);
		}
		
		A[P[x]]--;
		if(!A[P[x]]) {
			q.push(P[x]);
		}
	}
	ll res=(ll)(min(F[root],H[root]));
	res*=(ll)c;
	cout<<res<<endl;
	return 0;
}
