#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T,a;
    for(cin>>T;T--;){
        cin>>a;
        cout<<((a+1)%(a%100) ? "Bye\n" : "Good\n");
    }
    
}