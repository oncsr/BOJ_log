#include <iostream>
using namespace std;

int main(){
    int n, a, t=-1, s=0;
    for(cin>>n;n--;){
        cin>>a;
        if(a!=t+1) s+=a;
        t=a;
    }
    cout<<s;
}