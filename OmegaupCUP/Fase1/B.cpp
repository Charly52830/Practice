//https://omegaup.com/arena/omegacup1/practice/#problems/A-contar-lapices
#include<iostream>
using namespace std;

int main() {
	int n,k,a;
	scanf("%d %d",&n,&k);
	int c=0;
	for(int x=0;x<n;x++) {
		scanf("%d",&a);
		c+=a==k;
	}
		
	printf("%d\n",c);
	return 0;
}
