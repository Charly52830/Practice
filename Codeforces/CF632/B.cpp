//https://codeforces.com/contest/1333/problem/B
#include<iostream>
#define N 100010
using namespace std;
 
int A[N],B[N];
 
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a=N,b=N,c=N;
		for(int x=0;x<n;x++) {
			scanf("%d",A+x);
			if(A[x] == -1) {
				a=min(a,x);
			}
			else if(A[x] == 0) {
				b = min(b,x);
			}
			else {
				c = min(c,x);
			}
		}
		bool bul = 1;
		for(int x=0;x<n;x++) {
			scanf("%d",B+x);
			if(B[x] < A[x]) {
				bul &= x > a;
			}
			else if(B[x] > A[x]){
				bul &= x > c;
			}
		}
		if(bul)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
