//https://codeforces.com/contest/1277/problem/D
#include<set>
#include<map>
#include<iostream>
#define N 4000010
using namespace std;

int res[N];

string reverse(string s) {
	string res="";
	for(int x=s.size()-1;x>=0;x--) 
		res.push_back(s[x]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,x,a,b,c,d,j;
	string s;
	cin>>t;
	while(t--) {
		cin>>n;
		map<string,int> index;
		set<string> A,B;
		c=d=0;
		for(x=0;x<n;x++) {
			cin>>s;
			index[s]=x+1;
			if(s[0] == '0' && s[s.size()-1] == '1') 
				A.insert(s);
			else if(s[0] == '1' && s[s.size()-1] == '0') 
				B.insert(s);
			else if(s[0] == '0' && s[s.size()-1] == '0') 
				c++;
			else 
				d++;
		}
		if(c && d && c+d==n) {
			cout<<-1<<endl;
			continue;
		}
		a=A.size(),b=B.size(),j=0;
		set<string>::iterator it1=A.begin(),it2=B.begin();
		while(abs(a-b) > 1) {
			if(a>b) {
				if(!B.count(reverse(*it1))) {
					res[j++]=index[*it1];
					a--,b++;
				}
				it1++;
			}
			else {
				if(!A.count(reverse(*it2))) {
					res[j++]=index[*it2];
					a++,b--;
				}
				it2++;
			}			
		}
		cout<<j<<endl;
		for(x=0;x<j;x++) 
			cout<<res[x]<<" ";
		cout<<endl;
	}
	return 0;
}
