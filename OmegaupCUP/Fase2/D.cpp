//https://omegaup.com/arena/omegacup2/#problems/Saltos-de-rana
#include<vector>
#include<iostream>
#define N 100010
using namespace std;

int D[N];
vector<int> v;

int main() {
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int x=0;x<n;x++) {
		if(s[x] == '1') {
			v.push_back(x);
		}
	}
	bool bul=1;
	for(int x=1;x<v.size() && bul;x++) {
		int i=0,f=x;
		while(f-i > 1) {
			int k=f+i>>1;
			if(v[k] < v[x] - m)
				i=k;
			else
				f=k;
		}
		if(v[i] < v[x] - m) 
			i++;
		if(i == x)
			bul = 0;
		else 
			D[x] = D[i] + 1;		
	}
	if(bul)
		cout<<D[v.size() - 1]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
