#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,a,p=0,t=0;
    for(cin>>N;N--;){
        cin>>a;
        if(a>p){
            if(t)   return cout<<"NO",0;
        }
        else if(a<p){
            if(!t)  t++;
        }
        else    return cout<<"NO",0;
        p=a;
    }
    cout<<"YES";

}