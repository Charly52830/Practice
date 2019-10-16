//https://codeforces.com/gym/102219/problem/A
#include<iostream>
#define N 1010
using namespace std;

char s[110];
char M[N][N];
int A[256];
int n;
char B[]=">v<^";

void O(int r) {
	int x,y;
	for(x=0;x<n;x++) {
		for(y=0;y<n;y++) {
		
			if(M[x][y] == '.')
				printf(".");
			else {
				int k=A[M[x][y]];
				k=(k+r)%4;
				printf("%c",B[k]);
			}
		}
		printf("\n");
	}
}

void P(int r) {
	int x,y;
	for(y=0;y<n;y++) {
		for(x=n-1;x>=0;x--) {
			if(M[x][y] == '.')
				printf(".");
			else {
				int k=A[M[x][y]];
				k=(k+r)%4;
				printf("%c",B[k]);
			}
		}
			
		printf("\n");
	}
}

void C(int r) {
	int x,y;
	for(x=n-1;x>=0;x--) {
		for(y=n-1;y>=0;y--) {
			if(M[x][y] == '.')
				printf(".");
			else {
				int k=A[M[x][y]];
				k=(k+r)%4;
				printf("%c",B[k]);
			}
		}
		printf("\n");
	}
}

void D(int r) {
	int x,y;
	for(y=n-1;y>=0;y--) {
		for(x=0;x<n;x++) {
			if(M[x][y] == '.')
				printf(".");
			else {
				int k=A[M[x][y]];
				k=(k+r)%4;
				printf("%c",B[k]);
			}
		}
		printf("\n");
	}
}

int main() {
	A['>']=0;
	A['v']=1;
	A['<']=2;
	A['^']=3;
	int x;
	scanf("%d",&n);
	scanf("%s",s);
	for(x=0;x<n;x++)
		scanf("%s",M[x]);
	int a=0,b=0;
	for(x=0;s[x]!='\0';x++) 
		a+=s[x]=='R',b+=s[x]=='L';
	int res=(a%4 - b%4 +4) % 4;
	if(res==0) O(0);
	if(res==1) P(1);
	if(res==2) C(2);
	if(res==3) D(3);
	return 0;
}
