//https://codeforces.com/contest/1337/problem/B
#include<iostream>
using namespace std;
 
int main() {
	int t,x,n,m;
	scanf("%d",&t);
	while(t--) { 
		scanf("%d %d %d",&x,&n,&m);
		bool bul=0;
		if(x <= 10) 
			bul = m>0;
		else if(10 < x && x <= 20) 
			bul = m>1;
		else {
			for(int i=1;i<=m;i++) {
				int m1=min( m-i, n );
				int n1=n,x1=x;
				n1-=m1;
				while(m1--) 
					x1/=2;
				while(n1--) 
					x1= x1/2 + 10;
				if(x1 <= 10*i)
					bul = 1;
			}
		}
		
		
		
		if(bul)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
