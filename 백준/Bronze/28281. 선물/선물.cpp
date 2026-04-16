#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,X,p;
    cin>>N>>X>>p;
    int mn = 2e9;
    for(int i=1,a;i<N;i++){
        cin>>a;
        mn = min(mn, (a+p)*X);
        p = a;
    }
    cout<<mn;
    
}