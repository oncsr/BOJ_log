#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    char _;
    string a;
    cin>>_>>_>>a;
    string b = "1";
    for(int i=0;i<a.size();i++) b+='0';
    reverse(a.begin(), a.end());
    while(!a.empty() && a.back() == '0')    a.pop_back();
    reverse(a.begin(), a.end());
    cout<<"YES\n"<<a<<' '<<b;
}