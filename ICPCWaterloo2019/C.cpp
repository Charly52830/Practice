//https://codeforces.com/gym/102367/problem/C
#include<iostream>
#define N 1010
using namespace std;

char M[N][N];
int A[N];

int main() {
	int n,x,y,i,j;
	scanf("%d",&n);
	for(x=0;x<n;x++) {
		scanf("%s",M[x]);
		for(y=0;y<n;y++) {
			if(M[x][y] == 'K')
				i=x,j=y;
			A[x]+=M[x][y]=='*';
		}
	}
	int sum=0;
	bool bul=0;
	
	for(x=1;x<n;x++) {
		int count=0;
		if(abs(x-i)<=1) {
			if(M[x][j-1] == '*')
				M[x][j-1]='-',A[x]--;
			if(M[x][j] == '*')
				M[x][j]='-',A[x]--;
			if(M[x][j+1] == '*')
				M[x][j+1]='-',A[x]--;
		}
		for(y=0;y<n;y++) {
			if(y>0 && M[x-1][y-1]=='*' && M[x-1][y+1] == '*' && M[x][y] == '-') {
				count++;
				M[x-1][y-1]='-';
				M[x-1][y+1]='-';
			}
			bul|=M[x][y] == '*' && M[x][y+2]=='*' && M[x-1][y+1] == '*';
			bul|=y==1 && M[x-1][y-1] == '*' && M[x][y] == '*';
			bul|=y==n-2 && M[x-1][y+1] == '*' && M[x][y]=='*'; 
		}
		sum+=A[x-1]-count;
	}
	if(!bul)
		printf("%d\n",sum);
	else
		printf("-1\n");
	return 0;
}
