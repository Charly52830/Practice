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
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int const oo = 1e9;
int const mod = 1e9 + 7;

int A[18];

int solve(string s, int a){
    if(s=="hole in one") 
    	return 1;
    if(s=="condor") 
    	return max(1,a-4);
    if(s=="albatross") 
    	return max(1,a-3);
    if(s=="eagle") 
    	return max(1,a-2);
    if(s=="birdie") 
    	return max(1,a-1);
    if(s=="par") 
    	return a;
    if(s=="bogey") 
    	return a+1;
    if(s=="double bogey") 
    	return a+2;
    else
	return a+3;
}
    
int main(){
    //FASTIO
    string s;
    int ans=0;
    for(int i=0;i<18;i++){
        cin>>A[i];
    }
    getline(cin, s);
    for(int i=0;i<18;i++){
        //cin>>s;
        getline(cin, s);
        ans+=solve(s,A[i]);
    }
    cout<<ans<<endl;
    return 0;
}
