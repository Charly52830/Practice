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

int a,b,c;

int main() {
	scanf("%d %d %d",&a,&b,&c); 
	bool ab = a>=500;
	bool bb = b>=500;
    bool cb = c>=500;

    if(ab && bb && cb) {
        printf("%d",(a+b+c)-300);
    }else if(!ab && !bb && !cb ){
        printf("%d",(a+b+c));
    }else{
        if(ab){
            if((b+c)>=500){
                printf("%d",(a+b+c)-200);
            }else{
                printf("%d",(a+b+c)-100);
            }
        }else if(bb){
            if((a+c)>=500){
                printf("%d",(a+b+c)-200);
            }else{
                printf("%d",(a+b+c)-100);
            }
        }else if(cb){
            if((a+b)>=500){
                printf("%d",(a+b+c)-200);
            }else{
                printf("%d",(a+b+c)-100);
            }
        }
    }	
	  
	return 0;
}
