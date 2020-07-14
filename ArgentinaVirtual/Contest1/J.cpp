//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/J
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
 
vector<pii> v;
 
int main() {
	int n,d,a,b,x,y;
	scanf("%d %d",&n,&d);
	scanf("%d %d",&a,&b);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&x,&y);
		v.push_back(make_pair(x * a + y * b, i));
	}
	sort(v.begin(),v.end());
	vector<int> A;
	for(int i = 0; i < n && d > 0; i++) {
		d -= v[i].first;
		if(d >= 0) {
			A.push_back(v[i].second + 1);
		}
	}
	printf("%d\n", (int)A.size());
	for(auto i:A)
		printf("%d ",i);
	printf("\n");
	return 0;
}
