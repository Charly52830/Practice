//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
#include<iostream>
#define N 110
using namespace std;

int A[N];

int main() {
	int t,T,n;
	cin>>T;
	for(t=1;t<=T;t++) {
		cin>>n;
		int ans=0;
		for(int x=0;x<n;x++) cin>>A[x];
		for(int x=1;x<n-1;x++) ans+=A[x] > A[x-1] && A[x] > A[x+1];
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
