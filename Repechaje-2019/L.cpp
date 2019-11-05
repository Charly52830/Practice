//https://www.juezguapa.com/problemas/enunciado/lisp-to-infix-translator
#include<string.h>
#include<iostream>
#define N 15010
using namespace std;

char res[N],s[N];
int i,j;

void solve() {
	int cont=1;
	char op=s[i++];	//Operador
	while(cont) {
		if(s[i] == ')') 
			cont--;
		else if(s[i] == '(') {
			if(s[i+1] == op) {
				cont++;
				i++;
			}
			else {
				if(op=='*')
					res[j++]='(';
				i++;
				solve();
				if(op=='*')
					res[j++]=')';
				res[j++]=op;
				i--;
			}
		}
		else if(s[i] != 32) {
			res[j++]=s[i];
			res[j++]=op;
		}
		i++;
	}
	j--;
}

int main() {
	int t;
	scanf("%d%*c",&t);
	while(t--) {
		fgets(s,N,stdin);
		if(strlen(s) == 2) {
			printf("%s",s);
			continue;
		}
		i=1,j=0;
		solve();
		res[j]='\0';
		printf("%s\n",res);
	}
	return 0;
}
