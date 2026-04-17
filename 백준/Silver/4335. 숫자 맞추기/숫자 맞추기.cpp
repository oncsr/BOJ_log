#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int high = 10, low = 1, n;
    bool ans = 1;
    for(cin>>n;n;cin>>n){
        string a, b;
        cin>>a>>b;
        if(a == "too"){
            if(b == "high") high = min(high, n-1);
            else    low = max(low, n+1);
        }
        else{
            ans = low <= n && n <= high;
            cout<<(ans ? "Stan may be honest\n":"Stan is dishonest\n");
            high = 10, low = 1, ans = 1;
        }
    }

}