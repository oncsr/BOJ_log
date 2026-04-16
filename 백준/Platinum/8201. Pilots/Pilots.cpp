#include <bits/stdc++.h>
using namespace std;

int T, N, ans = 1;
deque<pair<int, int>> mx, mn;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>T>>N;
    for(int i=1,j=1,a;i<=N;i++) {
        cin>>a;
        while(!mn.empty() && mn.back().first > a) mn.pop_back();
        mn.emplace_back(a,i);
        while(!mx.empty() && mx.back().first < a) mx.pop_back();
        mx.emplace_back(a,i);
        while(j<i && mx.front().first - mn.front().first > T) {
            j++;
            while(mx.front().second < j) mx.pop_front();
            while(mn.front().second < j) mn.pop_front();
        }
        ans = max(ans, i-j+1);
    }
    cout<<ans;

}