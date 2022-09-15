#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;getline(cin,a);
    while(a != "***"){
        for(int i=a.size()-1;i>=0;i--)
            cout<<a[i];
        cout<<'\n';
        getline(cin,a);
    }
}