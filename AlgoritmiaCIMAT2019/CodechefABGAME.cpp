//https://www.codechef.com/problems/ABGAME
#include<iostream>
#define N 100010
using namespace std;

char s[N];
char A[256];

int main() {
	A['A']=1,A['B']=2;
	int t,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		int res=0,a=0,b=0,c=0;
		int i=0,sum=0;
		for(x=0;s[x]=='.';x++);
		for(;s[x]!='\0';x++) {
			if(s[x] == '.') 
				sum++;
			else {
				c++;
				if(i) {
					i|=A[s[x]];
					if(i==1)	//A con A
						a+=sum;
					else if(i==2) 	//B con B
						b+=sum;
					else 
						res^=sum;
					i=sum=0;
				}
				else
					i|=A[s[x]],sum=0;
			}
		}
		if(c&1) {
			int n=x;
			for(x=n-1;s[x]=='.';x--);
			if(s[x]=='A')
				a+=n-x-1;
			else
				b+=n-x-1;
		}
		if(a>b)
			printf("A\n");
		else if(a<b)
			printf("B\n");
		else {
			if(res)
				printf("A\n");
			else
				printf("B\n");
		}		
	}
	return 0;
}
