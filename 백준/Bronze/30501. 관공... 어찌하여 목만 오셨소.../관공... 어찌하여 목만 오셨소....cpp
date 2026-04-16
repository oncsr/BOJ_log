#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    for(cin>>N;N--;){
        string a;
        cin>>a;
        for(char i:a)   if(i == 'S')    return cout<<a,0;
    }
    
}