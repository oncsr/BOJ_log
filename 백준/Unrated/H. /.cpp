#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=1, b=1, p = 0, s=0;
    while(1){
        cout<<"? A "<< a<<endl;
        cin>>p;
        if(p) break;
        a++;
    }
    s+=a;
    while(1){
        cout<<"? B "<<b<<endl;
        cin>>p;
        if(p) break;
        b++;
    }
    cout<<"! "<<s+b;
}