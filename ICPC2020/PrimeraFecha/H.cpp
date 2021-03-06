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

int dp[61];

int main() {
    FASTIO
    int t, n, a;
    cin>>t;
    while (t){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(i==1) dp[i]=a;
            else{
                dp[i]=max(a+dp[i-2],dp[i-1]);
            }
        }
        cout<<dp[n]<<endl;
        t--;
        
    }
    return 0;
}
