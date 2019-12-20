//https://codeforces.com/contest/1272/problem/C
#include<iostream>
#define N 200010
using namespace std;
 
typedef long long ll;
 
int A[256];
char s[N];
 
ll f(int a) {
	return ((ll)a*(a+1))/2;
}
 
int main() {
	int n,x,m;
	char c;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	while(m--) {
		cin>>c;
		A[c]=1;
	}
	ll res=0;
	m=0;
	s[n]='$';
	for(x=0;x<=n;x++) {
		if(A[s[x]])
			m++;
		else 
			res+=f(m),m=0;
	}
	cout<<res<<endl;
	return 0;
}
