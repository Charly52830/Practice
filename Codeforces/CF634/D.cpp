//https://codeforces.com/contest/1335/problem/D
#include<iostream>
using namespace std;
 
char M[10][10];
int Y[]={0,3,6,1,4,7,2,5,8};
 
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		for(int x=0;x<9;x++) 
			scanf("%s",M[x]);
		for(int i=0;i<9;i++) {
			if(M[i][Y[i]] == '9')
				M[i][Y[i]] = '1';
			else
				M[i][Y[i]]++;
		}
		for(int x=0;x<9;x++) 
			printf("%s\n",M[x]);
	}
	return 0;
}
