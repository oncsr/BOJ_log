#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string a;
    cin>>a;
    if(a[1] == '0')   cout<<10 + stoi(a.substr(2,a.size()-2));
    else    cout<<int(a[0]-'0') + stoi(a.substr(1,a.size()-1));

}
