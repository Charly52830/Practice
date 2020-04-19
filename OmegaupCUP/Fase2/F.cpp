//https://omegaup.com/arena/omegacup2/#problems/Suma-de-vectores
#include<set>
#include<iostream>
#define N 110
using namespace std;

int A[N];

int main() {
	int n,k;
	cin>>n;
	for(int x=0;x<n;x++) {
		cin>>A[x];
	}
	for(int x=0;x<n;x++) {
		cin>>k;
		A[x]+=k;
	}
	for(int x=0;x<n;x++) {
		cout<<A[x]<<" ";
	}
	cout<<endl;
	return 0;
}
