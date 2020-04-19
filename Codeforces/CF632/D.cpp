//https://codeforces.com/contest/1333/problem/D
#include<stack>
#include<iostream>
#include<vector>
#define N 3010
using namespace std;
 
vector<stack<int> > v;
char s[N];
 
int main() {
	int n,k,sum=0;
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	bool bul=1;
	for(int x=0;bul;x++) {
		bool bul2=0;
		v.emplace_back();
		for(int y=0;y<n;y++) if(s[y] == 'R' && s[y+1] == 'L') 
			swap(s[y],s[y+1]),bul2=1,v[x].push(y+1),y++;
		bul&=bul2;
		sum+=v[x].size();
	}
	v.pop_back();
	if(sum < k || v.size() > k) 
		printf("-1\n");
	else {
		int i;
		for(i=0;k>v.size() - i;k--) {
			printf("1 %d\n",v[i].top()),v[i].pop();
			if(v[i].empty())
				i++;
		}
		for(;i<v.size();i++) {
			printf("%d ",(int)v[i].size());
			while(!v[i].empty()) 
				printf("%d ",v[i].top()),v[i].pop();
			printf("\n");
		}
	}
	return 0;
}
