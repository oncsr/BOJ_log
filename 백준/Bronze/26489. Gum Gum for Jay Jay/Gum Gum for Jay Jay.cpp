#include <iostream>
#include <string>
using namespace std;
int main(){
    int s=0;
    string a;
    while(getline(cin, a))
        s++;
    cout<<s;
}