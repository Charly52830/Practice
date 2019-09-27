//http://coj.uci.cu/24h/problem.xhtml?pid=2585
#include<iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	int t=s.size(),a=0,b=0,x;
	s.push_back('#');
	int sum=0,res=0;
	for(x=0;x<s.size();x++) {
		if(s[x]=='#') {
			res^=sum;
			sum=0;
			a++;
		}
		else {
			sum++;
			b++;
		}
	}
	a--;
	if(!res || a==t || b==t)
		cout<<"Rabbit\n";
	else
		cout<<"Cat\n";
	return 0;
}
