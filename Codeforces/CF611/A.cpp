//https://codeforces.com/contest/1283/problem/A
#include<iostream>
using namespace std;
 
int main() {
    int t,m,h;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&h,&m);
        printf("%d\n",(23-h)*60 + (60-m));
    }
    return 0;   
}
