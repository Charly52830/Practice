//https://codeforces.com/contest/1279/problem/B
#include<iostream>
using namespace std;
 
typedef long long ll;
 
 
int main() {
	int t,n,k,x,o;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&k);
		ll sum=0;
		int m=0,index_mayor=0,res=0;
		bool bul=1;
		for(x=0;x<n;x++) {
			scanf("%d",&o);
			if(o>m)
				index_mayor=x+1,m=o;
			sum+=o;
			if(sum>k && bul)
				res=index_mayor,bul=0,sum-=m;
		}
		printf("%d\n",res);
	}
	return 0;
}
