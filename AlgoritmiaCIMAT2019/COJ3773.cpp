//http://coj.uci.cu/24h/problem.xhtml?pid=3773
#include<bitset>
#include<vector>
#include<iostream>
#define N 31633
using namespace std;

bitset<N> B;

vector<int> criba() {
	vector<int> primos;
	for(int x=2;x<N;x++) if(!B[x]) {
		primos.push_back(x);
		for(int y=x*x;y<N;y+=x)
			B[y]=1;
	}
	return primos;
}

int main() {
	vector<int> primos=criba();
	int t,k,n,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int res=0;
		for(x=0;x<n;x++) {
			scanf("%d",&k);
			if(k>1) {
				for(auto p:primos) {
					if(p*p > k)
						break;
					int sum=0;
					while(!(k%p)) 
						k/=p,sum++;
					res^=sum;
				}
				if(k>1)
					res^=1;
			}
		}
		
		if(res)
			printf("Poo\n");
		else
			printf("Mak\n");
		
	}
	return 0;
}
