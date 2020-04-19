//https://codeforces.com/contest/1330/problem/C
#include<iostream>
#define N 100010
using namespace std;
 
int A[N],res[N];
 
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	bool bul=1;
	long long sum=0;
	for(int x=1;x<=m;x++) {
		scanf("%d",A+x);
		int f=n-A[x]+1;
		bul&=f>=x;
		sum+=A[x];
	}
	bul&=sum >= n;
	if(!bul) {
		printf("%d\n",-1);
		return 0;
	}
	else {
		int j=n;
		for(int x=m;x>0;x--) {
			int i = j-A[x]+1;
			if(i < x && x<=j)
				i = x;
			res[x] = i;
			j = i - 1;
		}
	}
	for(int x=1;x<=m;x++)
		cout<<res[x]<<" ";
	cout<<endl;
	return 0;
}
