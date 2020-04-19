//https://codeforces.com/contest/1328/problem/B
#include<math.h>
#include<iostream>
#define N 100010
using namespace std;
 
char A[N];
 
long long f(long long k) {	
	double d = sqrt(8*k + 1);
	int n = d;
	long long res = (1 + n)/2 - 1;
	if(res * (res + 1) / 2 == k)
		return res;
	return res + 1;
}
 
int main() {
	int t,n,k;
	scanf("%d",&t);
	for(int x = 0;x<N;x++)
		A[x] = 'a';
	while(t--) {
		scanf("%d %d",&n,&k);
		long long p = f(k);
		long long l = p * (p -1) / 2;
		long long pos2= k - l - 1;
		A[n - p - 1] = 'b';
		A[n - pos2 - 1] = 'b';
		A[n]='\0';
		printf("%s\n",A);
		A[n - p - 1] = 'a';
		A[n - pos2 - 1] = 'a';
		A[n]='a';
	}	
	
	return 0;
}
