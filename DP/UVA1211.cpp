//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3652
#include<iostream>
#define N 110
using namespace std;

int A[N];
double F[10010],dp[N];

double f(int x,int r,double v,double e,double f1) {
	if(x>=r) 
		return 1/(v-e*(x-r));
	else 
		return 1/(v-f1*(r-x));
}

int main() {
	int n,x,a,c;
	scanf("%d",&n);
	while(n) {
		double b,v,e,f1;
		int r;
		for(x=0;x<n;x++) 
			scanf("%d",A+x);
		scanf("%lf",&b);
		scanf("%d",&r);
		scanf("%lf",&v);
		scanf("%lf",&e);
		scanf("%lf",&f1);
		F[0]=0;
		for(x=1;x<=A[n-1];x++) 
			F[x]=F[x-1] + f(x-1,r,v,e,f1);
		for(int i=0;i<n;i++) {
			dp[i]=F[A[i]];
			for(int j=0;j<i;j++) 
				dp[i]=min(dp[i], dp[j]+b+F[A[i]-A[j]]);
		}
		printf("%.4lf\n",dp[n-1]);
		scanf("%d\n",&n);
	}
	return 0;
}
