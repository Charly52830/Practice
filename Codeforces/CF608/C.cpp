//https://codeforces.com/contest/1271/problem/C
#include<iostream>
using namespace std;
 
int main() {
	int n,s_x,s_y,b,x,y,c1=0,c2=0,c3=0,c4=0;
	scanf("%d %d %d",&n,&s_x,&s_y);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&x,&y);
		c1+=y>s_y;
		c3+=y<s_y;
		c2+=x>s_x;
		c4+=x<s_x;
	}
	if(c1>= c2 && c1>=c3 && c1>=c4) 
		printf("%d\n%d %d\n",c1,s_x,s_y+1);
	else if(c2>=c1 && c2>=c3 && c2>=c4) 
		printf("%d\n%d %d\n",c2,s_x+1,s_y);
	else if(c3>= c1 && c3>=c2 && c3>=c4) 
		printf("%d\n%d %d\n",c3,s_x,s_y-1);
	else
		printf("%d\n%d %d\n",c4,s_x-1,s_y);
	return 0;
}
