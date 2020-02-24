//https://codeforces.com/contest/1311/problem/B
#include<set>
#include<iostream>
#define N 110
using namespace std;
 
int A[N];
 
int main() {
	int t,n,m,x,k,y;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		set<int> s;
		for(x=1;x<=n;x++) 
			scanf("%d",A+x);
		for(x=1;x<=m;x++) {
			scanf("%d",&k);
			s.insert(k);
		}
		
		for(y=1;y<=n;y++) {
			for(x=1;x<=n;x++) {
				if(A[x] > A[x+1] && s.count(x)) {
					swap(A[x],A[x+1]);
				}
			}
		}
		
		bool bul=0;
		for(x=1;x<n;x++) 
			bul|= !(A[x+1] >= A[x]);
		if(bul) 
			printf("NO\n");
		else
			printf("YES\n");
		
	}
	return 0;
}
