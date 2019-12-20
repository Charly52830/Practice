//https://codeforces.com/contest/1272/problem/A
#include<algorithm>
#include<iostream>
using namespace std;
 
int A[3];
 
int main() {
	int q;
	scanf("%d",&q);
	while(q--) {
		scanf("%d %d %d",&A[0],&A[1],&A[2]);
		sort(A,A+3);
		if(A[0] == A[2] || A[2]-A[0] == 1)
			printf("%d\n",0);
		else
			printf("%d\n",abs((A[2]-A[0])-2)*2);
	}
	
	return 0;
}
