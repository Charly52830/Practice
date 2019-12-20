//https://codeforces.com/contest/1272/problem/B
#include<iostream>
#define N 100010
using namespace std;
 
char s[N];
int A[256];
 
int main() {
	int q,x;
	scanf("%d",&q);
	while(q--) {
		scanf("%s",s);
		A['D']=A['U']=A['L']=A['R']=0;
		for(x=0;s[x]!='\0';x++) 
			A[s[x]]++;
		A['D'] = min(A['D'],A['U']);
		A['U'] = min(A['D'],A['U']);
		A['L'] = min(A['L'],A['R']);
		A['R'] = min(A['L'],A['R']);
		if(A['D']==0 || A['R'] == 0) {
			if(A['D']==0 && A['R'] == 0) {
				printf("%d\n",0);
				printf("\n");
			}
			else if(A['D'] == 0) {
				printf("2\n");
				printf("LR\n");
			}
			else {
				printf("2\n");
				printf("UD\n");
			}
		}
		else {
			printf("%d\n",A['D'] + A['U']+A['L']+A['R']);
			while(A['D']--)
				printf("D");
			while(A['L']--)
				printf("L");
			while(A['U']--)
				printf("U");
			while(A['R']--)
				printf("R");
			printf("\n");
		}
	}
	
	return 0;
}
