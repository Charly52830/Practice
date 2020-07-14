//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/E
#include<iostream>
#define N 100010
using namespace std;
 
typedef long long ll;
 
int A[N];
ll B[N],C[N];
 
int main() {
	int n;
	scanf("%d",&n);
	for(int x=0;x<n;x++)
		scanf("%d",A+x);
	B[0] = A[0];
	C[n - 1] = A[n - 1];
	for(int x=1;x<n;x++)
		B[x] = B[x - 1] + A[x], C[n - x - 1] = C[n - x] + A[n - x - 1];
	int a=0,b;
	for(int x=0;x < n; x++)
		a+= B[x] <= C[x];
	b=n - a;
	
	printf("%d %d\n",a,b);
	return 0;
}

