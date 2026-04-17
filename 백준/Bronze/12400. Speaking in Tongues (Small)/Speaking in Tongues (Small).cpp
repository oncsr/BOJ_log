#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin>>T;
    cin.ignore();
    map<char, char> M;
    M['a'] = 'y', M['y'] = 'a';
    M['e'] = 'o', M['o'] = 'k';
    M['j'] = 'u', M['u'] = 'j';
    M['p'] = 'r', M['r'] = 't';
    M['m'] = 'l', M['l'] = 'g';
    M['s'] = 'n', M['n'] = 'b';
    M['b'] = 'h', M['c'] = 'e';
    M['d'] = 's', M['f'] = 'c';
    M['g'] = 'v', M['h'] = 'x';
    M['i'] = 'd', M['k'] = 'i';
    M['t'] = 'w', M['v'] = 'p';
    M['w'] = 'f', M['x'] = 'm';
    M['q'] = 'z';
    M['z'] = 'q';

    int tc = 1;
    for(;T--;){
        string s;
        getline(cin, s);
        cout<<"Case #"<<tc++<<": ";
        for(char i:s){
            if(i != ' ')    cout<<M[i];
            else    cout<<' ';
        }
        cout<<'\n';
    }

}