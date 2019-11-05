//https://www.juezguapa.com/problemas/enunciado/hidden-lists
#include<iostream>
#define N 70
using namespace std;

char s[N];
int n;

int solve(int i,int m) {
	if(i == n) 
		return 1;
	int sum=0,res=0;
	while(sum<=m && i<n) 
		sum=sum*10 + (s[i++]-'0');
	while(m < sum && sum<=1000000) {
		res+=solve(i,sum);
		sum=sum*10 + s[i++]-'0';
	}
	return res;
}

int main() {	
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve(0,0));
	return 0;
}
