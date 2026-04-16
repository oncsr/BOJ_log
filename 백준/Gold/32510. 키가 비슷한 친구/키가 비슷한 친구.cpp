// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T, tc = 0;
    for(cin>>T;T--;){
        ll N, K;
        cin>>N>>K;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
        vector<pair<int, int>> arr(N);
        int c = 0;
        for(auto &[a,b] : arr)  cin>>a, b = ++c;
        sort(arr.begin(), arr.end());
        
        ll ans = 0;
        for(auto &[v,i] : arr){
            while(!Q.empty() && Q.top().second < v - K)    Q.pop();
            if(!Q.empty())  ans += max(0, i - Q.top().first);
            Q.emplace(i,v);
        }
        cout<<"Case #"<<++tc<<'\n';
        cout<<ans<<'\n';
    }
    
}