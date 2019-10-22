//Carlos Ruvalcaba
//Equipo: #include<uaz>
#include<iostream>
using namespace std;

int main() {
	int n,m,m1=0,m2=0,k,x;
	scanf("%d %d",&n,&m);
	for(x=0;x<n;x++) 
		scanf("%d",&k),m1=max(m1,k);
	for(x=0;x<m;x++)
		scanf("%d",&k),m2=max(m2,k);
	if(m1==m2)
		printf("possible\n");
	else
		printf("impossible\n");
	return 0;
}
