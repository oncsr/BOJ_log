#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a;
    getline(cin,a);
    cout<<(a[0] == '\"' && a.back() == '\"' && a.size() > 2 ? a.substr(1,a.size()-2) : "CE");
    
}