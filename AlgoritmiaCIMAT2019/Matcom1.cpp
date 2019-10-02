//https://matcomgrader.com/problem/9610/un-juego-facil/
#include<algorithm>
#include<set>
#include<iostream>
#define N 100010
using namespace std;

int movs[40];
int grundy[N];
int A[N];

int mex(set<int> s) {
	int x=0;
	for(auto i:s) {
		if(i==x)
			x++;
		else
			return x;
	}
	return x;
}

int main() {
	int t,n,m,y,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		for(x=0;x<m;x++)
			scanf("%d",movs+x);
		sort(movs,movs+m);
		int ma=0;
		for(x=0;x<n;x++) 
			scanf("%d",A+x),ma=max(ma,A[x]);
		for(x=0;x<=ma;x++) {
			set<int> s;
			for(y=0;y<m && x>=movs[y];y++)
				s.insert(grundy[x-movs[y]]);
			grundy[x]=mex(s);
		}
		int res=0;
		for(x=0;x<n;x++) 
			res^=grundy[A[x]];
		if(res)
			printf("Gana el primer jugador.\n");
		else
			printf("Gana el segundo jugador.\n");
	}		
	return 0;
}
