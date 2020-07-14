//https://codeforces.com/group/j1UosVRZar/contest/287329/problem/D
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    int n,a,b,ans=0,total,k;
    cin>>n>>a>>b;
    total=a+2*b;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==1){
            if(a>0){
                a--;
                total--;
            }
            else if(b>0){
                b--;
                total--;
            }
            else if(total>0){
                total--;
            }
            else
                ans++;
        }
        if(k==2){
            if(b>0){
                b--;
                total-=2;
            }
            else
                ans+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
