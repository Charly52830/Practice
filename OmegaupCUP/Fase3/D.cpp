//https://omegaup.com/arena/loc3/#problems/itp18-direcciones
#include<iostream>
#define N 110
using namespace std;

int X[]={-1,0,1,0};
int Y[]={0,-1,0,1};

int M[N][N];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int x=0;x<n;x++) {
		for(int y=0;y<m;y++) {
			scanf("%d",&M[x][y]);
		}
	}
	int x=0,y=0;
	int direccion = 3;
	while(x >=0 && x < n && y >=0 && y < m && !(x == n-1 && y == m-1)) {
		if(M[x][y] == 1) 
			direccion = (direccion +3)%4;
		else if(M[x][y] == 2) 
			direccion = (direccion +1)%4;
		else if(M[x][y] == 3) 
			direccion = (direccion + 2)%4;
		x+=X[direccion];
		y+=Y[direccion];
	}
	if(x == n-1 && y == m-1)
		cout<<"llegaste\n";
	else
		cout<<"te perdiste\n";
	return 0;
}
