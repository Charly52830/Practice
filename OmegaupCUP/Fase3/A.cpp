//https://omegaup.com/arena/loc3/#problems/Trituradores-de-Basura
#include<set>
#include<iostream>
#define M 1510
using namespace std;

set<int> v[10];

bool f(string s) {
	int cur = -1;
	for(char c:s) {
		if(cur == -1) 
			cur = c-'0';
		else if(v[cur].count(c-'0'))
			cur = c-'0';
		else
			return 0;
	}
	return 1;
}

bool B[M];

int main() {
	v[0] = {0};
	v[1] = {1,2,3,4,5,6,7,8,9,0};
	v[2] = {2,5,3,6,8,9,0};
	v[3] = {3,6,9};
	v[4] = {4,5,6,7,8,9,0};
	v[5] = {5,6,8,9,0};
	v[6] = {6,9};
	v[7] = {7,8,9,0};
	v[8] = {8,9,0};
	v[9] = {9};
	for(int x=1;x<M;x++) 
		B[x] = f(to_string(x));
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int i,j;
		for(i=n;i<M && !B[i];i++);
		for(j=n;j>=0 && !B[j];j--);
		if(n-j <= i-n)
			printf("%d\n",j);
		else
			printf("%d\n",i);
	}
	return 0;
}
