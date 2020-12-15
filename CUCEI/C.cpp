#include <math.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string nombres[100010];

int const oo = 1e9;
int const mod = 1e9 + 7;

int main() {
	FASTIO
	int n,k,sum=0, ind;
	cin>>n;
	forn(i,n){
	    cin>>nombres[i];
	    sum+=nombres[i].size();
	}
	cin>>k;
	ind=k/sum;
	ind=ind%n;
	k=k%sum;
	while(k){
	    if(nombres[ind].size()<k){
	        k-=nombres[ind].size();
	        ind=(ind+1)%n;
	    }
	    else{
	        cout<<nombres[ind][k-1]<<endl;
	        return 0;
	    }
	}
	return 0;
}
