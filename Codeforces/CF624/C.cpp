//https://codeforces.com/contest/1311/problem/C
#include<string.h>
#include<iostream>
#define N 200010
using namespace std;
 
char s[N];
int A[N];
long long B[26];
 
int main() {
	int t,n,m,x,k;
	scanf("%d",&t);
	s[0]='$';
	while(t--) {
		scanf("%d %d",&n,&m);
		scanf("%s",&s[1]);
		for(x=0;x<=n;x++)
			A[x]=0;
		A[1]=m+1;
		for(x=1;x<=m;x++) {
			scanf("%d",&k);
			A[k+1]--;
		}
		memset(B,0,sizeof B);
		long long sum=0;
		for(x=1;x<=n;x++) {
			sum+=A[x];
			B[s[x]-'a']+=sum;
		}
		for(x=0;x<26;x++)
			cout<<B[x]<<" ";
		cout<<endl;
	}
	return 0;
}
