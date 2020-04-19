//https://omegaup.com/arena/omegacup2/#problems/Analizar-palabra
#include<set>
#include<iostream>
using namespace std;

int main() {
	string s;
	set<char> vocales;
	vocales.insert('a');
	vocales.insert('e');
	vocales.insert('i');
	vocales.insert('o');
	vocales.insert('u');
	vocales.insert('A');
	vocales.insert('E');
	vocales.insert('I');
	vocales.insert('O');
	vocales.insert('U');
	cin>>s;
	int v=0;
	for(auto c:s) {
		v+=vocales.count(c);
	}
	cout<<s.size()<<endl<<v<<endl;
	for(int x=s.size()-1;x>=0;x--) {
		cout<<s[x];
	}
	cout<<endl;
	return 0;
}
