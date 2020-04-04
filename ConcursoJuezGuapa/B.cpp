#include<map>
#include<iostream>
#define N 1000010
using namespace std;

map<string,int> mapa;
int j;

int A[N],B[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin>>n;
	for(int x=0;x<n;x++) {
		cin>>s;
		mapa[s]=j++;
	}
	for(int x=0;x<n;x++) {
		cin>>s;
		A[x] = mapa[s];
		B[mapa[s]] = max(mapa[s],x);
	}
	bool bul = 0;
	int i,f;
	for(int x=0;x<n;x++) {
		if(!bul) {	// No está dentro de un campo
			i=x,f=max(B[x],B[A[x]]);
			bul=1;
		}
		int tf=max(B[x],B[A[x]]);
		if(x == f && tf == f) {
			cout<<f - i + 1 <<endl;
			bul = 0;
		}
		else if(tf > f)
			f = tf;		
	}	
	return 0;
}
