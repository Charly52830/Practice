//https://matcomgrader.com/problem/9612/las-dos-torres/
#include<iostream>
using namespace std;

int main() {
	int t,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		if(a&1 && b&1 )
			printf("Gana el segundo jugador.\n");
		else
			printf("Gana el primer jugador.\n");
	}
	return 0;
}
