#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, H = 1, h = 1, D[1000001]{};
    cin>>N;
    iota(D, D+N+1, 0);
    for(int i=2;h<=N;i++){
        h = H+4*i-3;
        if(h > N)   break;
        D[h] = 1;
        for(int j=h+1;j<=N;j++){
            D[j] = min(D[j], D[j-h] + 1);
        }
        H = h;
    }
    cout<<D[N];

}