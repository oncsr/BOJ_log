#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, s = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if(a == 136)    s++;
        if(a == 142)    s+=5;
        if(a == 148)    s+=10;
        if(a == 154)    s+=50;
    }
    cout<<s*1000;
    
}