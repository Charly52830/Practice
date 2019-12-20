//https://codeforces.com/contest/1277/problem/C
#include<vector>
#include<iostream>
#define N 1500010
using namespace std;
 
char s[N];
 
bool f(int i,string S) {
	bool bul=0;
	for(int x=0;x<S.size();x++) 
		bul|=S[x]!=s[x+i];
	return !bul;
}
 
int main() {
	int t,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		vector<int> v;
		for(x=0;s[x]!='\0';x++) {
			if(f(x,"twone")) {
				s[x+2]='$';
				v.push_back(x+2);
			}
			else if(f(x,"two") || f(x,"one")) {
				s[x+1]='$';
				v.push_back(x+1);
			}
		}
		printf("%d\n",(int)v.size());
		for(auto i:v)
			printf("%d ",i+1);
		printf("\n");
	}
	
	return 0;
}
