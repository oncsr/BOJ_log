#include<iostream>
using namespace std;
int main(){
    int n,a,s=0,b=0;
    for(cin>>n;n--;){
        cin>>a;
        s+=a,b=max(b,a);
    }
    cout<<s-b;
}