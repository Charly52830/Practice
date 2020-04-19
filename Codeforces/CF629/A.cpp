//https://codeforces.com/contest/1328/problem/A
#include<iostream>
using namespace std;
 
int main() {
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		int r = a % b;
		int n = (a - r) / b;
		int nb = (n + 1)*b;
		if(a%b == 0)
			cout<<0<<endl;
		else
			cout<<nb - a <<endl;
	}
	return 0;
}
