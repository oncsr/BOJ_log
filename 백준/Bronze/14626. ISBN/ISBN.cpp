#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin>>s;
    for(int i=0;i<10;i++) {
        int c = 0, x = 3;
        for(int j=0;j<s.size();j++) {
            x ^= 2;
            if(s[j] == '*') c += x*i;
            else c += x*(s[j]-'0');
        }
        if(c%10 == 0) return cout<<i,0;
    }

}