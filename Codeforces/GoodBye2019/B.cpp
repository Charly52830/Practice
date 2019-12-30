//https://codeforces.com/contest/1270/problem/B
#include<iostream>
#define N 200010
using namespace std;
 
int A[N];
 
int main() {
	int t,n,a,b,x,k,res;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(x=0;x<n;x++)
			scanf("%d",A+x);
		bool bul=0;
		for(x=0;x<n-1;x++) {
			if(abs(A[x+1]-A[x])>=2) {
				bul=1,res=x;
			}
		}
		if(bul)
			printf("YES\n%d %d\n",res+1,res+2);
		else
			printf("NO\n");
	}
	return 0;
}
