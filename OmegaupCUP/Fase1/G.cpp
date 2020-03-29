//https://omegaup.com/arena/omegacup1/practice/#problems/Karel-y-los-quebrados
#include<set>
#include<vector>
#include<iostream>
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

int main() {
	int n;
	cin>>n;
	vector<int> v;
	for(int x=1;x*x <= n;x++) {
		if(n % x == 0) {
			v.push_back(x);
			if(n/x != x)
				v.push_back(n/x);
		}
	}
	set<pii> s;
	for(int x=0;x<v.size();x++) {
		for(int y =x;y<v.size();y++) {
			int a=v[x],b=v[y];
			int nk=n*(a+b);
			a=(nk/a), b=(nk/b);
			s.insert(mp(min(a,b),max(a,b)));
		}
	}
	printf("%d\n",(int)s.size());
	for(auto i:s) 
		printf("1/%d = 1/%d + 1/%d\n",n,i.second,i.first);
	return 0;
}
