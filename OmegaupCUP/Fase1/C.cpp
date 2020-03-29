//https://omegaup.com/arena/omegacup1/practice/#problems/nofib
#include<iostream>
#define N 30010
using namespace std;

int A[N];

int main() {
	int a=0,b=1,c;
	for(;a+b<N;c=b,b+=a,a=c) 
		A[a+b] = 1;
	int n;
	scanf("%d",&n);
	for(int x=1;x<n;x++) {
		if(!A[x])
			printf("%d ",x);
	}
	printf("\n");
	return 0;
}
