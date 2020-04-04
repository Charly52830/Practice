#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	string linea; 
	map<string,int> palabras;
	for(int i = 0;i<n;i++){
		cin>>linea;
		if(palabras.find(linea)!=palabras.end()){
			palabras[linea]++;
		}else{
			palabras[linea]=1;
		}
	}	
	
	int max = -1;
	for(auto par:palabras){
		if(max<par.second){
			max = par.second;
		}
	}
	set<string> elejidas;
	for(auto par:palabras){
		if(par.second == max){
			elejidas.insert(par.first);
		}
	}
	
	for(auto elejida:elejidas){
		cout<<elejida<<endl;
	}
}

