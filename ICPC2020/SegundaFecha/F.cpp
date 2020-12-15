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

int const oo = 1e9;
int const mod = 1e9 + 7;

bool gana(int lo,int vi,bool ser){
    if(ser){
        if(lo+1>=5){
            if(lo-vi+1>=2 or lo+1==10) return true;
        }
        
    }
    else{
        if(vi+1>=5){
            if(vi-lo+1>=2 or vi+1==10) return true;
        }
    }
    return false;
}

int main() {
	FASTIO
	string s;
	int gl=0,gv=0,pl=0,pv=0;
	bool serv=true;
	cin>>s;
	forn(i,s.size()){
	    if(s[i]=='S'){
	        if(gana(pl,pv,serv)){
	            if(serv){
	                gl++;
	                pl=0;
	                pv=0;
	            }
	            else{
	                gv++;
	                pl=0;
	                pv=0;
	            }
	        }
	        else{
	            if(serv) pl++;
	            else pv++;
	        }
	    }
	    else if(s[i]=='R'){
	        serv=!serv;
	        if(gana(pl,pv,serv)){
	            if(serv){
	                gl++;
	                pl=0;
	                pv=0;
	            }
	            else{
	                gv++;
	                pl=0;
	                pv=0;
	            }
	        }
	        else{
	            if(serv) pl++;
	            else pv++;
	        }
	    }
	    else{
	        if(gl==2 or gv==2){
	            if(gl==2) printf("%d (winner) - %d\n",gl,gv);
	            else printf("%d - %d (winner)\n",gl,gv);
	        }
	        
	        else if(serv) printf("%d (%d*) - %d (%d)\n",gl,pl,gv,pv);
	        else printf("%d (%d) - %d (%d*)\n",gl,pl,gv,pv);
	    }
	}
	return 0;
}
