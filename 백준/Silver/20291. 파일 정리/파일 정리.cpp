#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<string, int> S;
    for(cin>>n;n--;){
        string a;
        cin>>a;
        string t = "";
        bool f = 0;
        for(char i:a){
            if(f)   t += i;
            if(i == '.')    f = 1;
        }
        S[t]++;
    }
    for(auto [a,b]:S)   cout<<a<<' '<<b<<'\n';
}