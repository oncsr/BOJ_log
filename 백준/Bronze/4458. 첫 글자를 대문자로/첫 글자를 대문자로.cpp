#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    for(cin.ignore();N--;){
        string s;
        getline(cin, s);
        if(s[0] >= 'a') s[0] -= 32;
        cout<<s<<'\n';
    }
}