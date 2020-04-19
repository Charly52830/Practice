//https://omegaup.com/arena/omegacup4/#problems/Gato-ruso
#include<string.h>
#include<iostream>
#define N 110
using namespace std;

int M[N][N];
int A[N][N];
int B[N][N];
int C[N][N];
int D[N][N];
int X[N][N];
int Y[N][N];

int n;

int f(int x,int y) {
	int sum=0;
	for(int i=1;x-i >=0 && y+i <n && M[x-i][y+i] == 1;i++)
		sum++;
	for(int i=1;x+i <n && y-i >=0 && M[x+i][y-i] == 1;i++)
		sum++;
	return sum;
}

int F(int x,int y) {
	int sum=0;
	for(int i=1;x-i >=0 && y-i >=0 && M[x-i][y-i] == 1;i++)
		sum++;
	
	for(int i=1;x+i<n && y+i <n && M[x+i][y+i] == 1;i++)
		sum++;
	return sum;
}

int main() {
	int m,x,y,k;
	cin>>n>>m;
	while(m--) {
		cin>>y>>x>>k;
		k++;
		M[n-x][y-1]=k;
	}
	for(int x=0;x<n;x++) {
		for(int y=0;y<n;y++) {
			if(M[x][y] == 1)
				A[x][y] = 1 + (y>0 && M[x][y-1] == 1?A[x][y-1]:0);
		}
		for(int y=n-1;y>=0;y--) {
			if(M[x][y] == 1)
				B[x][y] = 1 + (M[x][y+1] == 1?B[x][y+1]:0);
		}
	}
	for(int y=0;y<n;y++) {
		for(int x=0;x<n;x++) {
			if(M[x][y] == 1) 
				C[x][y] = 1 + (x>0 && M[x-1][y] == 1? C[x-1][y]:0);
		}
		for(int x=n-1;x>=0;x--) {
			if(M[x][y] == 1)
				D[x][y] = 1 + (M[x+1][y] == 1?D[x+1][y]:0);
		}
	}
	for(int x=0;x<n;x++) {
		for(int y=0;y<n;y++) {
			if(M[x][y] == 0) {
				
				int sum=0;
				if(y>=0)
					sum+=A[x][y-1];
				if(y<n)
					sum+=B[x][y+1];
				int sum2=0;
				if(x>=0)
					sum2+=C[x-1][y];
				if(x<n)
					sum2+=D[x+1][y];
				int sum3 = f(x,y);
				int sum4 = F(x,y);
				if(sum >=4 || sum2 >= 4 || sum3 >=4 || sum4 >=4)
					cout<<y+1<<" "<<n-x<<endl;
			}
		}
	}
	return 0;
}
