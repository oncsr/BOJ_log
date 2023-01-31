#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    for(cin>>T;T--;){
        int N, d[100002][2]{};
        cin>>N;
        for(int i=2;i<N+2;i++)  cin>>d[i][0];
        for(int i=2;i<N+2;i++)  cin>>d[i][1];
        for(int i=2;i<N+2;i++){
            d[i][0] = max({d[i-1][1], d[i-2][0], d[i-2][1]}) + d[i][0];
            d[i][1] = max({d[i-1][0], d[i-2][0], d[i-2][1]}) + d[i][1];
        }
        cout<<max({d[N][0], d[N][1], d[N+1][0], d[N+1][1]})<<'\n';
    }
}