//https://matcomgrader.com/problem/9611/jugando-con-las-potencias/
#include<set>
#include<iostream>
#define N 100010
using namespace std;

int movs[]={1,4,27,256,3125,46656};
int grundy[N];

int mex(set<int> s) {
	int x=0;
	for(auto i:s) {
		if(i==x)
			x++;
		else
			return x;
	}
	return x;
}

int main() {
	int t,x,n,k;
	for(x=1;x<N;x++) {
		set<int> s;
		for(auto i:movs) if(x>=i)
			s.insert(grundy[x-i]);
		grundy[x]=mex(s);
	}
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int res=0;
		for(x=0;x<n;x++) 
			scanf("%d",&k),res^=grundy[k];
		if(res)
			printf("Gana el primer jugador.\n");
		else
			printf("Gana el segundo jugador.\n");
	}
	return 0;
}
