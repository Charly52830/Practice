//http://coj.uci.cu/24h/problem.xhtml?pid=1646
#include<iostream>
using namespace std;

int main() {
	int n,m,x,k;
	while(scanf("%d %d",&n,&m)!=EOF) {
		int res=0;
		for(x=0;x<n;x++)
			scanf("%d",&k),res^=k;
		if(res)
			printf("Vida\n");
		else
			printf("Andrea\n");
	}
	return 0;
}
