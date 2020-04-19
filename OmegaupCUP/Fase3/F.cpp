//https://omegaup.com/arena/loc3/#problems/Contando-Estudiantes
#include<iostream>
using namespace std;

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

int main() {
	BIT bit(1000010);
	int q,a,b;
	scanf("%d",&q);
	while(q--) {
		scanf("%d %d",&a,&b);
		if(a == 1) 
			bit.range_sum(b,1000000,1);
		else 
			cout<<bit.query(b)<<endl;
	}
	return 0;
}
