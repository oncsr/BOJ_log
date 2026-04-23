#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b-2*c<0?a+b:a+b-2*c);
}