#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string a;
    cin>>a;
    map<char, string> M;
    M['0'] = "000";
    M['1'] = "001";
    M['2'] = "010";
    M['3'] = "011";
    M['4'] = "100";
    M['5'] = "101";
    M['6'] = "110";
    M['7'] = "111";
    string ans = "";
    for(char i:a)   ans += M[i];
    int s = 1;
    for(char i:ans){
        if(s && i == '0')   continue;
        s = 0;
        cout<<i;
    }
    if(s)   cout<<0;

}