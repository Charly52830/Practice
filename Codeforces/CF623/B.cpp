//https://codeforces.com/contest/1315/problem/B
#include<iostream>
#define N 100010
using namespace std;
 
int main() {
	int t,a,b,p,x;
	string s;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&a,&b,&p);
		cin>>s;
		s[s.size()-1]='$';
		int res=s.size();
		for(x=s.size()-2;x>=0;x--) {
			if(s[x]!=s[x+1]) {
				if(s[x] == 'A')
					p-=a;
				else
					p-=b;
			}
			if(p>=0)
				res=x+1;
			else 
				break;
		}
		printf("%d\n",res);
	}
	return 0;
}
