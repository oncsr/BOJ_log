#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    stack<ii> S;
    int ans[400000]{};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        while(!S.empty() && a <= S.top().first){
            ans[S.top().second] = i - S.top().second;
            S.pop();
        }
        S.push({a, i});
    }
    for(int i=0;i<n;i++){
        if(ans[i])  cout<<ans[i];
        else    cout<<"infinity";
        cout<<'\n';
    }
    
}