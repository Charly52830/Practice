//https://omegaup.com/arena/omegacup1/practice/#problems/Tu-y-tu-Futuro
#include<vector>
#include<iostream>
#define N 500010
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

class BIT {
	
	private :
	int *tree;
	int n;
	
	void add(int k, int x) {
		while(k <= n) {
			tree[k] += x;
			k += k&-k;
		}
	}
	
	public :
	
	BIT(int len) {
		n = len;
		tree = (int*)malloc((n + 1) * sizeof(int));
		for(int x=0;x<n;x++) 
			tree[x] = 0;
	}
	
	void range_sum(int i, int j, int k) {
		add(i, k);
		add(j + 1, -k);
	}
	
	int query(int k) {
		
		int s = 0;
		while(k >= 1) {
			s += tree[k];
			k -= k&-k;
		}		
		return s;
	}
};

vector<pii> v[N];
ll BS[N];
int R[N];
int res[N];

int binary_search(int d,ll k) {
	int i=1,f=d;
	while(i < f) {
		int m=i+f>>1;
		if(BS[d - 1] - BS[m - 1] > k)
			i = m + 1;
		else
			f = m;
	}
	return i;
}

void dfs(int n,BIT &bit, int d=1) {
	for(auto p:v[n]) {
		BS[d] = p.second + BS[d - 1];
		dfs(p.first,bit,d+1);
	}
	res[n] = bit.query(d);
	bit.range_sum(d,d,-res[n]);
	bit.range_sum(binary_search(d,R[n]),d - 1, 1);
}

int main() {
	int n,a,b,c;
	scanf("%d",&n);
	for(int x=1;x < n;x++) {
		scanf("%d %d %d",&a,&b,R+x);
		v[a].push_back(mp(x,b));	// nodo, costo
	}
	BIT bit(n);
	dfs(0,bit);
	for(int x=0;x<n;x++) 
		printf("%d ",res[x]);
	printf("\n");
	return 0;
}
