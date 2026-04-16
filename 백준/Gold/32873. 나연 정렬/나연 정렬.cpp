#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> V;
    int N, a;
    for(cin>>N;N--;){
        cin>>a;
        auto p = lower_bound(V.begin(), V.end(), a);
        if(p == V.end())    V.push_back(a);
        else    *p = a;
    }
    cout<<V.size();

}