#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin>>s;
    sort(s.begin(), s.end(), greater<>());
    int c = 0;
    for(char i:s)   c += i-'0';
    if(s.back() == '0' && c%3 == 0) cout<<s;
    else    cout<<-1;

}