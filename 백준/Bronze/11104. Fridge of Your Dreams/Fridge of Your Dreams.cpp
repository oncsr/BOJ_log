#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    for(cin>>T;T--;){
        bitset<24> B;
        cin>>B;
        cout<<B.to_ulong()<<'\n';
    }
}