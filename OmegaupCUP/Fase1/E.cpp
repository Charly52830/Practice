//https://omegaup.com/arena/omegacup1/practice/#problems/estacion
#include<iostream>
using namespace std;

int main() {
	int E[]={580,980,1190,1250,1420};
	int n;
	scanf("%d",&n);
	if(!(540 <= n && n <= 1520))
		printf("error\n");
	else {
		int m=0;
		for(int i=1;i<5;i++) {
			if(abs(E[i] - n) <= abs(E[m] - n))
				m = i;
		}
		if(E[m] > n)
			printf("adelante %d\n",E[m] - n);
		else
			printf("atras %d\n",n - E[m]);
	}
	return 0;
}
