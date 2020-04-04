#include <iostream>
#include <stdio.h>

int dp[100000],m[100000];

using namespace std;

int main()
{
    int n, i, sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m[i];
        sum+=m[i];
    }
    if(n==1)
        cout<<"0 0"<<endl;
    else if(n==2)
        cout<<sum<<" "<<min(m[0],m[1])<<endl;
    else{
        m[1]+=m[0];
        m[n-2]+=m[n-1];
        for(i=2;i<n-1;i++){
            dp[i]=min(m[i]+dp[i-1],m[i-1]+dp[i-2]);
        }
        cout<<2*sum<<" "<<dp[n-2]+m[0]+m[n-1]<<endl;
    }
    return 0;
}

