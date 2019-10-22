//Carlos Ruvalcaba
//Equipo: #include<uaz>
#include<set>
#include<queue>
#include<iostream>
#define N 1010
#define oo 1000000000
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

int n,m,k;
int M[N][N];
int dis[N][N];

int X[]={-1,0,1,0};
int Y[]={0,-1,0,1};

pii i_to_p(int x) {
	return mp(x/m,x%m);
}

int p_to_i(pii p) {
	return p.first*m + p.second;
}

int dijkstra(int h) {
	priority_queue<pii,vector<pii>,greater<pii> > q;	//Costo, indice
	int x,y;
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++)
			dis[x][y]=-1;
	}
	for(x=0;x<m;x++) 
		q.push(mp(M[0][x]<h,x));
	int res=oo;
	while(!q.empty()) {
		pii p=i_to_p(q.top().second);
		x=p.first,y=p.second;
		int d=q.top().first;
		q.pop();
		if(dis[x][y]!=-1)
			continue;
		dis[x][y]=d;
		if(x==n-1)
			res=min(res,d);
		for(int i=0;i<4;i++) {
			int x1=x+X[i];
			int y1=y+Y[i];
			if(x1>=0 && x1<n && y1>=0 && y1<m && dis[x1][y1]==-1) {
				pii p1=mp(x1,y1);
				q.push(mp( d + (M[x1][y1]<h), p_to_i(p1)));
			}
		}
	}
	return res;
}

int main() {
	int x,y;
	scanf("%d %d %d",&n,&m,&k);
	set<int> s;
	for(x=0;x<n;x++) {
		for(y=0;y<m;y++) {
			scanf("%d",&M[x][y]);
			s.insert(M[x][y]);
		}
	}
	int j=0;
	int n1=s.size();
	int C[n1];
	for(auto a:s) 
		C[j++]=a;
	int i=0,f=n1-1;
	while(f-i>1) {
		int half=i+f>>1;
		if(dijkstra( C[half] ) >k)
			f=half;
		else
			i=half;
	}
	if(dijkstra(C[f])<=k)
		printf("%d\n",C[f]);
	else
		printf("%d\n",C[i]);
	return 0;
}

