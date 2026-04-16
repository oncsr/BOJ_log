#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,M;
    cin>>N>>M;
    string a[10]{};
    for(int i=0;i<N;i++){
        cin>>a[i];
        reverse(a[i].begin(), a[i].end());
        cout<<a[i]<<'\n';
    }
    
}