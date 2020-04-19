//https://codeforces.com/contest/1335/problem/C
#include<map>
#include<iostream>
using namespace std;
 
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		map<int,int> mapa;
		for(int x=0;x<n;x++) {
			scanf("%d",&k);
			mapa[k]++;
		}
		int M=0;
		for(auto p:mapa) {
			int key=p.first,val=p.second;
			M=max(M, min((int)mapa.size() - 1, val) );
			M=max(M, min((int)mapa.size(), val -1));
		}
		printf("%d\n",M);
	}
	return 0;
}
