//https://codeforces.com/contest/1270/problem/C
#include<iostream>
#define N 100010
using namespace std;
 
typedef long long ll;
 
int main() {
	int t,n;
	ll sum=0,k,XOR=0;
	scanf("%d",&t);
	while(t--) {
		cin>>n;
		XOR=sum=0;
		while(n--) {
			cin>>k;
			sum+=k;
			XOR^=k;
		}
		cout<<2<<endl<<XOR<<" "<<sum+XOR<<endl;
	}
	return 0;
}
