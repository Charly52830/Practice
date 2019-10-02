//https://www.codechef.com/submit/TUZGMBR
#include<iostream>
using namespace std;

int g1(int x) {
	return x%4;
}

int g2(int x) {
	return x%3;
}

int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		int g=g1(n-1)^g2(m-1);
		if(g)
			printf("Tuzik\n");
		else
			printf("Vanya\n");
	}	
	return 0;
}
