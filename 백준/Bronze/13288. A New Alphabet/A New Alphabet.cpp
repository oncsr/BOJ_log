#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string arr[26] = {
        "@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"
    };
    string s;
    getline(cin, s);
    for(char i:s){
        if(65 <= i && i <= 90)   cout<<arr[i-'A'];
        else if(97 <= i && i <= 122)    cout<<arr[i-'a'];
        else    cout<<i;
    }

}