//https://codeforces.com/contest/1279/problem/C
#include<set>
#include<iostream>
#define N 100010
using namespace std;
 
typedef long long ll;
 
int index[N];
 
int main() {
	int t,n,m,x,k;
	scanf("%d",&t);
	while(t--) {
		set<int> s;
		scanf("%d %d",&n,&m);
		for(x=0;x<n;x++) {
			scanf("%d",&k);
			index[k]=x;
		}
		ll sum=0;
		for(x=0;x<m;x++) {
			scanf("%d",&k);
			s.insert(-index[k]);
			if(-index[k] == *s.begin())
				sum+=(index[k] - (s.size()-1))*2+1;
			else
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
