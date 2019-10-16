//https://codeforces.com/gym/102219/problem/I
#include <iostream>
 
using namespace std;
 
string s1,s2,s3;
 
int main(){
    bool bul1=0;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    for(int j=0;j<10;j++){
        if(bul1&&(s1[j]!='.')){
            cout<<s1[j]<<endl;
            return 0;
        }
        if(s1[j]=='='&&(j!=9))
            bul1=1;
    }
    bul1=0;
    for(int j=0;j<10;j++){
        if(bul1&&(s2[j]!='.')){
            cout<<s2[j]<<endl;
            return 0;
        }
        if(s2[j]=='='&&j!=9){
            bul1=1;
        }
    }
    bul1=0;
    for(int j=0;j<10;j++){
        if(bul1&&(s3[j]!='.')){
            cout<<s3[j]<<endl;
            return 0;
        }
        if(s3[j]=='='&&j!=9)
            bul1=1;
    }
    cout<<"You shall pass!!!"<<endl;
    return 0;
}
