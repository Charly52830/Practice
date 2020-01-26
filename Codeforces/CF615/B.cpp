//https://codeforces.com/contest/1294/problem/B
#include<algorithm>
#include<iostream>
#define mp make_pair
#define N 1010
using namespace std;
 
typedef pair<int,int> pii;
 
bool f(pii a,pii b) {
	return a.first + a.second <= b.first + b.second;
}
 
string f2(pii a,pii b) {
	int x = abs(b.first - a.first);
	int y = abs(b.second - a.second);
	string ans="";
	while(x--)
		ans.push_back('R');
	while(y--)
		ans.push_back('U');
	return ans;
}
 
pii A[N];
 
int main() {
	int t,n,a,b,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		A[0]=mp(0,0);
		for(x=1;x<=n;x++) {
			scanf("%d %d",&a,&b);
			A[x]=mp(a,b);
		}
		sort(A,A+n+1,f);
		
		bool bul=1;
		string res="";
		for(x=0;x<n;x++) {
			if(A[x].first <= A[x+1].first && A[x].second <=A[x+1].second) 
				res+=f2(A[x],A[x+1]);
			else 
				bul=0;
			
		}
		if(bul)
			cout<<"YES\n"<<res<<endl;
		else
			cout<<"NO\n";
	}
	return 0;
}
