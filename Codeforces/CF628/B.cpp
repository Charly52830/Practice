//https://codeforces.com/contest/1325/problem/B
#include<set>
#include<iostream>
using namespace std;
 
 
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		set<int> s;
		for(int x=0;x<n;x++) {
			scanf("%d",&k);
			s.insert(k);
		}
		
		printf("%d\n",(int)s.size());
	}
	return 0;
}
