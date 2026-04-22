#include <iostream>
using namespace std;
int main(){
    int a,m,x;
    cin>>a>>m;
    for(x=0;a*x%m!=1;x++);
    cout<<x;
}