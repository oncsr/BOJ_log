#include <iostream>
using namespace std;

int main(){
    int n, s=0;
    char a;
    cin>>n;
    while(n--){
        cin>>a;
        s += (a=='1');
    }
    cout<<s;
}