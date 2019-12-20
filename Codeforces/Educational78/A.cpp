//https://codeforces.com/contest/1278/problem/A
#include<string.h>
#include<set>
#include<iostream>
#define N 110
using namespace std;
 
int A[256];
char s[N],S[N];
 
int main() {
	int t,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		scanf("%s",S);
		memset(A,0,sizeof A);
		int n=strlen(s),m=strlen(S);
		set<char> Set;
		for(x=0;x<n;x++) {
			Set.insert(s[x]);
			A[s[x]]++;
		}
		int cnt=Set.size();
		bool bul=0;
		for(x=0;x<n;x++) {
			if(Set.count(S[x])) {
				
				if(A[S[x]] == 0)
					cnt++;
				
				A[S[x]]--;
				
				if(A[S[x]] == 0)
					cnt--;
				
			}
		}
		bul|=cnt==0;
		for(x=n;x<m;x++) {
			if(Set.count(S[x])) {
				
				if(A[S[x]] == 0)
					cnt++;
				
				A[S[x]]--;
				
				if(A[S[x]] == 0)
					cnt--;
				
			}
			if(Set.count(S[x-n])) {
				if(A[S[x-n]] == 0)
					cnt++;
				
				A[S[x-n]]++;
				if(A[S[x-n]] == 0) 
					cnt--;
			}
			bul|=cnt==0;
		}
 
		if(bul)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}

