//https://omegaup.com/arena/omegacup1/practice/#problems/Rango-simple
#include<iostream>
#define N 110
using namespace std;

int A[N];

int main() {
	int n,a,b,c=0;
	scanf("%d",&n);
	for(int x=0;x<n;x++)
		scanf("%d",A+x);
	scanf("%d %d",&a,&b);
	for(int x=0;x<n;x++) 
		c+= a<=A[x] && A[x] <= b;
	printf("%d\n",c);
	return 0;
}
