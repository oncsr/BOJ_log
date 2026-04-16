#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> T;
    for(int i=1,s=1;s<=1000;s+=(++i))   T.push_back(s);
    
    int t,a;
    for(cin>>t;t--;){
        cin>>a;
        bool p = 0;
        for(int i:T)for(int j:T)for(int k:T){
            if(i+j+k == a)  p=1;
        }
        cout<<(p ? "1\n" : "0\n");
    }
    
}