//https://codeforces.com/contest/1330/problem/B
#include<vector>
#include<set>
#include<iostream>
#define N 200010
#define mp make_pair
using namespace std;
 
typedef pair<int,int> pii;
 
int A[N],B[N];
 
int main() {
	int n,t;
	scanf("%d",&t);
	while(t-- ) {
		scanf("%d",&n);
		for(int x=0;x<n;x++) {
			scanf("%d",A+x);
			B[x] = 0;
		}
		set<int> s,S;
		for(int x=0;x<n;x++) {
			s.insert(A[x]);
			S.insert(-A[x]);
			if(s.size() == x + 1 && *s.begin() == 1 && *S.begin() == - (x + 1))  {
				B[x] = 1;
			}
				
		}
		set<int> tmp_s,tmp_S;
		swap(tmp_s,s);
		swap(tmp_S,S);
		vector<pii> res;
		for(int x=n-1;x>0;x--) {
			s.insert(A[x]);
			S.insert(-A[x]);
			if(s.size() == n - x && *s.begin() == 1 && *S.begin() == - (n - x) && B[x-1]) {
				res.push_back(mp(x,n-x));
			}
		}
		printf("%d\n",(int)res.size());
		for(auto p:res)
			printf("%d %d\n",p.first,p.second);
	}
 
	return 0;
}

