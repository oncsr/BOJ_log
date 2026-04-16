#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, inf = -1234567890;
    cin>>N;
    vector<int> D(500001, inf);
    for(int i=0,a;i<N;i++){
        cin>>a;
        vector<int> ND(500001, inf);
        ND[a] = a;
        for(int j=0;j<=500000;j++){
            if(D[j] == inf) continue;
            ND[abs(j-a)] = max(ND[abs(j-a)], D[j] + a);
            ND[j+a] = max(ND[j+a], D[j] + a);
            ND[j] = max(ND[j], D[j]);
        }
        D = ND;
    }
    if(D[0] == inf) cout<<-1;
    else    cout<<D[0]/2;

}