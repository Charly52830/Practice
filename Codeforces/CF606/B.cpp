//https://codeforces.com/contest/1277/problem/B
#include<set>
#include<iostream>
using namespace std;
 
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		set<int> s;
		scanf("%d",&n);
		while(n--) {
			scanf("%d",&k);
			if(!(k&1))
				s.insert(-k);
		}
		int res=0;
		while(!s.empty()) {
			k=*s.begin();
			s.erase(k);
			k=(-k)/2;
			if(!(k&1))
				s.insert(-k);
			res++;
		}
		printf("%d\n",res);
	}
	
	return 0;
}

