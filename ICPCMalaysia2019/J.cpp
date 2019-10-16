//https://codeforces.com/gym/102219/problem/J
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

vector<int> v[256];
char s[10];
int A[256];
queue<int> q;
vector<char> toposort;

int main() {
	int t=5,a,b,x;
	while(t--) {
		scanf("%s",s);
		a=s[0],b=s[2];
		if(s[1] == '>') {
			v[a].push_back(b);
			A[b]++;
		}
		else {
			v[b].push_back(a);
			A[a]++;
		}
	}
	for(x='A';x<='E';x++) {
		if(A[x]==0)
			q.push(x);
	}
	int k=0;
	while(!q.empty()) {
		x=q.front();
		toposort.push_back((char)x);
		q.pop();
		k++;
		for(auto j:v[x]) {
			A[j]--;
			if(A[j] == 0)
				q.push(j);
		}
	}
	if(k==5) {
		for(x=4;x>=0;x--)
			printf("%c",toposort[x]);
		printf("\n");
	}
	else 
		printf("impossible\n");	
	return 0;
}
