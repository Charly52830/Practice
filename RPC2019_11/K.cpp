//Carlos Ruvalcaba
//Equipo: #include<uaz>
#include<map>
#include<iostream>
using namespace std;

map<int,int> mapa;

void erase(int x) {
	if(mapa.count(x)) {
		mapa[x]--;
		if(mapa[x]==0)
			mapa.erase(x);
	}
}

int min() {
	map<int,int>::iterator it=mapa.begin();
	return it->first;
}

int B[28];

int main() {
	int n,x,k;
	scanf("%d",&n);
	for(x=0;x<(1<<n);x++) {
		scanf("%d",&k);
		mapa[k]++;
	}
	int j=0,y=0;
	for(x=0;x<=n;x++) {
		if(y>0)
			B[j++]=min();
		for(;y<(1<<x);y++) {
			int sum=0;
			for(int i=0;i<x;i++) {
				if(y&(1<<i))
					sum+=B[i];
			}
			erase(sum);
		}
	}
	if(mapa.size() == 0) {
		for(x=0;x<j;x++)
			printf("%d\n",B[x]);
	}
	else
		printf("impossible\n");	
	return 0;
}
