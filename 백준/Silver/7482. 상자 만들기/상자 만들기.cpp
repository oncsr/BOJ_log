#include <iostream>
using namespace std;

int main(){
    int n;
    cout.precision(10);
    for(cin>>n;n--;){
        double a;
        cin>>a;
        cout<<fixed<<a/6<<'\n';
    }
}