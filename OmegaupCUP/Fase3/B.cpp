//https://omegaup.com/arena/loc3/#problems/Instancias-de-clases
#include<set>
#include<map>
#include<iostream>
#define N 35
using namespace std;

map<string,int> mapa;
char entrada[1010];
char variable[1010],deshecho[1010];
int A[N];

int main() {
	int n,m,c=0;
	scanf("%d",&n);
	scanf("%d%*c",&m);
	for(int x=0;x<n;x++) {
		fgets(entrada,1010,stdin);
		sscanf(entrada,"%s %s = new %s",deshecho,variable,deshecho);
		string str(variable);
		mapa[str]=c;
		A[x]=c++;
	}
	for(int x=0;x<m;x++) {
		fgets(entrada,1010,stdin);
		sscanf(entrada,"%s = %s",variable,deshecho);
		string str1(variable),str2(deshecho);
		str2.pop_back();
		int a=mapa[str1],b=mapa[str2];
		A[a] = b;
	}
	set<int> s;
	for(int x=0;x<n;x++) 
		s.insert(A[x]);
	printf("%d\n",(int)s.size());
	return 0;
}
