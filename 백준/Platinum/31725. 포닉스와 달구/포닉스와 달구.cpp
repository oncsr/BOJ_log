#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int N, K;
ui arr[2002][2002]{}, UL[2002][2002]{}, RD[2002][2002]{}, UR[2002][2002]{}, DL[2002][2002]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin>>arr[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) UL[i][j] = max(UL[i-1][j], UL[i][j-1]) + arr[i][j];
    for(int i=N;i>=1;i--) for(int j=N;j>=1;j--) RD[i][j] = max(RD[i+1][j], RD[i][j+1]) + arr[i][j];
    for(int i=1;i<=N;i++) for(int j=N;j>=1;j--) UR[i][j] = max({UR[i-1][j], UR[i][j+1], UL[i][j] + RD[i][j] - arr[i][j]});
    for(int i=N;i>=1;i--) for(int j=1;j<=N;j++) DL[i][j] = max({DL[i+1][j], DL[i][j-1], UL[i][j] + RD[i][j] - arr[i][j]});

    ui ans = 4e9;
    for(int i=K;i<=N;i++) for(int j=K;j<=N;j++) {
        if((i == K && j == K) || (i == N && j == N)) continue;
        ui res = 0;
        if(i < N && j > K) res = max(res, DL[i+1][j-K]);
        if(i > K && j < N) res = max(res, UR[i-K][j+1]);
        ans = min(ans, res);
    }
    cout<<ans;

}