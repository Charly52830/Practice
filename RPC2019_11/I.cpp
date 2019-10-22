//Luis Fernando García Acosta. 
//Equipo: #include<uaz>
#include <iostream>
int numeros[1000005];
long long suma[1000005];
int n,actual;
long long powactual;
long long maxactual=0;
int main(){	
	numeros[0]=0;
	scanf("%d",&n);
	for(int i = 1; i<=n;i++){
			scanf("%d",&actual);
			numeros[i]=actual;
			suma[i]=suma[i-1]+actual;
	}	
	for(int x=1;x<=n;x++){
		powactual+=numeros[x]*numeros[x];
		long long resultado= powactual*((long long)(suma[n]-suma[x]));
		if(resultado>maxactual){
			maxactual=resultado;
		}
	}
	std::cout << maxactual << std::endl;
	return 0;
}
