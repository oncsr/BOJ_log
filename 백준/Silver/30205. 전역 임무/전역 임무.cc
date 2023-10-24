#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N, M, P;
    cin>>N>>M>>P;
    for(int i=0;i<N;i++){
        priority_queue<ll, vector<ll>, greater<>> Q;
        ll g = 0;
        for(int j=0;j<M;j++){
            ll a;
            cin>>a;
            if(a < 0)   g++;
            else    Q.push(a);
        }
        while(!Q.empty()){
            if(P >= Q.top()){
                P += Q.top();
                Q.pop();
            }
            else{
                while(g > 0 && P < Q.top()){
                    P <<= 1;
                    g--;
                }
                if(!g && P < Q.top()){
                    cout<<0;
                    return 0;
                }
            }
        }
        if(g > 0)   P <<= g;
    }
    cout<<1;
}