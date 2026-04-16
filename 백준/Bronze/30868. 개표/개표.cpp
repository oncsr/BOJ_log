#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T, a;
    for(cin>>T;T--;){
        cin>>a;
        for(int i=0;i<a/5;i++)  cout<<"++++ ";
        for(int i=0;i<a%5;i++)  cout<<'|';
        cout<<'\n';
    }

}