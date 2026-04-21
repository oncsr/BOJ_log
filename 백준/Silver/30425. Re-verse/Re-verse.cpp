#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    string a;
    cin>>a;
    int ans = 1;
    for(int i=1;i<N;i++){
        bool can = 1;
        for(int j=0;j<N;j++){
            if(i+j>=a.size())    a.push_back(a[j]);
            if(a[i+j] != a[j])    {can = 0;break;}
        }
        if(can) ans++;
    }
    cout<<ans;
}