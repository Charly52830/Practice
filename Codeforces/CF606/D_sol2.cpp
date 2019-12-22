//https://codeforces.com/contest/1277/problem/D
#include<map>
#include<set>
#include<string.h>
#include<iostream>
#define N 4000010
#define A1 (911382323)
#define B1 (972663749)
#define A (16807)
#define B (2147483647)
#define mp make_pair
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
char s[N];
int res[N];
 
pii Hash(char *S) {
	ll h=s[0];
	int x;
	for(x=1;S[x]!='\0';x++) 
		h=(h*A+S[x])%B;
	//Reverse hash
	ll h1=S[--x];
	for(x--;x>=0;x--) 
		h1=(h1*A+S[x])%B;
	return mp(h,h1);
}
 
int main() {
	int t,x,n,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		set<int> hashes[4];
		map<int,int> reverse,index;
		for(x=0;x<n;x++) {
			scanf("%s",s);
			pii p=Hash(s);
			int len=strlen(s);
			if(*s == '0' && s[len-1] == '1') 
				hashes[0].insert(p.first);
			else if(*s == '1' && s[len-1] == '0') 
				hashes[1].insert(p.first);
			else if(*s == '0' && s[len-1] == '0')
				hashes[2].insert(p.first);
			else
				hashes[3].insert(p.first);
			reverse[p.first]=p.second;
			index[p.first]=x+1;
		}
		if(hashes[2].size() && hashes[3].size() && hashes[2].size() + hashes[3].size() == n) {
			printf("-1\n");
			continue;
		}
		set<int>::iterator h0=hashes[0].begin(), h1=hashes[1].begin();
		a=hashes[0].size(),b=hashes[1].size();
		int j=0;
		while(abs(a-b) >1) {
			if(a>b) {
				if(!hashes[1].count(reverse[*h0])) {
					res[j++]=index[*h0];
					a--,b++;
				}
				h0++;
			}
			else {
				if(!hashes[0].count(reverse[*h1])) {
					res[j++]=index[*h1];
					a++,b--;
				}
				h1++;
			}
		}
		printf("%d\n",j);
		for(x=0;x<j;x++) 
			printf("%d ",res[x]);
		printf("\n");
	}
	return 0;
}
