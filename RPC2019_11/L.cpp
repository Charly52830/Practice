//Carlos Ruvalcaba
//Equipo: #include<uaz>
#include<iostream>
using namespace std;

typedef long long ll;

int main() {
	ll l,n;
	int res=1;
	cin>>l>>n;
	while(l%n) 
		n-=l%n,res++;
	cout<<res<<endl;
	return 0;
}
