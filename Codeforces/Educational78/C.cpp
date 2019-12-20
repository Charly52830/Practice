//https://codeforces.com/contest/1278/problem/C
#include<vector>
#include<iostream>
#define N 200010
#define oo 1000000010
using namespace std;
 
int J[N];
bool C[N],D[N];
 
int main() {
	int t,n,x,y;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a=0,b=0;
		for(x=0;x<2*n;x++) {
			scanf("%d",J+x);
			a+=J[x]==1;
			b+=J[x]==2;
			D[x]=C[x]=0;
		}
		vector<int> A,B;
		int count_a=0,count_b=0,dif;
		for(x=n-1;x>=0;x--) {
			if(J[x] == 1) {
				count_a++;
				dif=count_a-count_b;
				if(dif>0 && !C[dif] && a>b) {
					C[dif]=1;
					A.push_back(n-x);
				}		
			}
			else {
				count_b++;
				dif=count_b-count_a;
				if(dif > 0 && !C[dif] && b>a) {
					C[dif]=1;
					A.push_back(n-x);
				}	
			}
		}
		
		count_a=count_b=0;
		for(x=n;x<2*n;x++) {
			if(J[x] == 1) {
				count_a++;
				dif=count_a-count_b;
				if(dif>0 && !D[dif] && a>b) {
					D[dif]=1;
					B.push_back(x-n+1);
				}
			}
			else {
				count_b++;
				dif=count_b-count_a;
				if(dif > 0 && !D[dif] && b>a) {
					D[dif]=1;
					B.push_back(x-n+1);
				}
			}
		}
		int res=oo;
		dif=abs(a-b);
		if(dif && A.size() >= dif) 
			res=A[dif-1];
		if(dif && B.size() >= dif) 
			res=min(res,B[dif-1]);
		if(dif > 1) {
			if(A.size() < dif-1)
				x=A.size()-1;
			else
				x=dif-2;
			for(y=dif-(x+1)-1;x>=0 && y<(int)B.size();x--,y++) 
				res=min(res,A[x]+B[y]);		
		}
		if(dif == 0)
			res=0;
		printf("%d\n",res);
	}
	return 0;
}
