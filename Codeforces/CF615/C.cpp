//https://codeforces.com/contest/1294/problem/C
#include<map>
#include<vector>
#include<iostream>
#define N 31633
using namespace std;
 
typedef pair<int,int> pii;
 
int B[N];
vector<int> primos;
 
void criba(int n) {
	long long x,y;
	B[0]=B[1]=1;
	primos.push_back(2);
	for(x=3;x<n;x+=2) {
		if(B[x] == 0) {
			primos.push_back(x);
			for(y = x*x; y<n;y+=x) {
				B[x]=1;
				
			}
		}
	}
}
 
int pow(int n,int k) {
	int res=1;
	while(k--)
		res*=n;
	return res;
}
 
int main() {
	criba(N);
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		map<int,int> mapa;
		int n1=n;
		for(auto primo:primos) {
			while(n1%primo == 0) {
				mapa[primo]++;
				n1/=primo;
			}
		}
		if(n1 > 1) 
			mapa[n1]=1;
		if(mapa.size() == 1) {
			pii p=*mapa.begin();
			if(p.second <=5) 
				cout<<"NO\n";
			else {
				cout<<"YES\n"<<p.first<<" "<<pow(p.first,2)<<" "<<pow(p.first,p.second - 3)<<endl;
			}
		}
		else if(mapa.size() == 2) {
			map<int,int>::iterator it=mapa.begin();
			pii p=*it;
			it++;
			pii p2=*it;
			it++;
			if(p.second + p2.second <4) 
				cout<<"NO\n";
			else 
				cout<<"YES\n"<<p.first<<" "<<p2.first<<" "<<n/(p.first*p2.first)<<endl;
		}
		else {
			map<int,int>::iterator it=mapa.begin();
			pii p=*it;
			it++;
			pii p2=*it;
			it++;
			cout<<"YES\n"<<p.first<<" "<<p2.first<<" "<<n/(p.first*p2.first)<<endl;
		}
	}
	return 0;
}
