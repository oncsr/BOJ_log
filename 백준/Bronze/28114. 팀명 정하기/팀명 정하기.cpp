#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, less<>> Q;
    priority_queue<int, vector<int>, greater<>> q2;
    for(int i=0;i<3;i++){
        int a, b;
        string s;
        cin>>a>>b>>s;
        q2.emplace(b%100);
        Q.emplace(a, s[0]);
    }
    while(!q2.empty())  cout<<q2.top(), q2.pop();
    cout<<'\n';
    while(!Q.empty())   cout<<Q.top().second, Q.pop();

}