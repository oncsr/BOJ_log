#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    string s;
    cin>>N>>s;
    for(char i:s)   cout<<(i == 'I' ? 'i' : 'L');
    
}