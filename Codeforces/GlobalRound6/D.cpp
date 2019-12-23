//https://codeforces.com/contest/1266/problem/D
#include<vector>
#include<iostream>
#define N 100010
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

ll A[N],res3[3*N];
int res1[3*N], res2[3*N];
vector<pii> source,sink;

int main() {
	int n,m,x,a,b,c,tam_res=0;
	scanf("%d %d",&n,&m);
	for(x=0;x<m;x++) {
		scanf("%d %d %d",&a,&b,&c);
		A[b]+=c;
		A[a]-=c;
	}
	for(x=1;x<=n;x++) {
		if(A[x]>0) 
			sink.push_back(mp(x,A[x]));
		else if(A[x]<0) 
			source.push_back(mp(x,-A[x]));
	}
	int i=0,j=0;
	while(i<sink.size() && j<source.size()) {
		if(!sink[i].second) 
			i++;
		else if(!source[j].second) 
			j++;
		else {
			res1[tam_res]=source[j].first;
			res2[tam_res]=sink[i].first;
			ll k=min(sink[i].second,source[j].second);
			res3[tam_res++]=k;
			sink[i].second-=k;
			source[j].second-=k;
		}
	}
	printf("%d\n",tam_res);
	for(x=0;x<tam_res;x++) 
		cout<<res1[x]<<" "<<res2[x]<<" "<<res3[x]<<endl;
	return 0;
}
