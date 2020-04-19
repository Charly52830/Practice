//https://omegaup.com/arena/loc3/#problems/Display-Led
#include<queue>
#include<iostream>
#define N 310
#define mp make_pair
#define oo 90000
using namespace std;

typedef pair<int,int> pii;

class DisjointSet {
	private:
	int *A,*S;
	int C;

	public:
	
	DisjointSet(int n) {
		A=(int*)malloc(n*sizeof(int));
		S=(int*)malloc(n*sizeof(int));
		for(int x=0;x<n;x++) {
			A[x]=x;
			S[x]=1;
		}
		C=n;
	}
		
	int padre(int x) {
		if(x!=A[x])
			A[x]=padre(A[x]);
		return A[x];
	}
	
	void unir(int i,int j) {
		int a=padre(i);
		int b=padre(j);
		if(a==b)
			return;
		C--;
		if(S[a]<S[b])
			swap(a,b);
		S[a]+=S[b];
		A[b]=a;
	}
		
	int getComponentes() {
		return C;
	}
	
	int getTam(int x) {
		return S[x];
	}
		
};

bool M[N][N];
bool V[N][N];

int X[]={-1,0,1,0};
int Y[]={0,-1,0,1};
int n,m;

int ctp(int x,int y) {
	return x*m +y;
}

pii ptc(int p) {
	return mp(p/m,p%m);
}

void BFS(DisjointSet &ds,int x,int y) {
	queue<pii> q;
	q.push(mp(x,y));
	int p=ctp(x,y);
	while(!q.empty()) {
		x=q.front().first,y=q.front().second;
		q.pop();
		if(V[x][y])
			continue;
		V[x][y] = 1;
		ds.unir(p,ctp(x,y));
		for(int i=0;i<4;i++) {
			int x1=x+X[i];
			int y1=y+Y[i];
			if(x1>=0 && x1<n && y1>=0 && y1<m && M[x1][y1]) 
				q.push(mp(x1,y1));
		}
	}
}

int main() {
	string s;
	cin>>n>>m;
	for(int x=0;x<n;x++) {
		cin>>s;
		for(int y=0;y<m;y++) 
			M[x][y]=s[y] == 'X';
	}
	DisjointSet ds(n*m);
	for(int x=0;x<n;x++) {
		for(int y=0;y<m;y++) {
			if(M[x][y] && !V[x][y]) {
				BFS(ds,x,y);
			}
		}
	}
	int res_M=0,res_m = oo;
	for(int x=0;x<n;x++) {
		for(int y=0;y<m;y++) {
			if(M[x][y]) {
				res_M=max(res_M,ds.getTam(ds.padre(ctp(x,y))));
				res_m=min(res_m,ds.getTam(ds.padre(ctp(x,y))));
			}
		}
	}
	if(res_m == oo && res_M == 0)
		res_m = 0;
	cout<<res_M<<endl<<res_m<<endl;
	return 0;
}
