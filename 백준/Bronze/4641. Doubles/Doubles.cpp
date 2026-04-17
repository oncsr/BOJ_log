#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    for(cin>>n;n != -1;cin>>n){
        vector<int> v;
        v.push_back(n);
        for(cin>>n;n;cin>>n)   v.push_back(n);
        int ans = 0;
        for(int i:v){
            for(int j:v){
                if(j == 2*i)    ans++;
            }
        }
        cout<<ans<<'\n';
    }

}