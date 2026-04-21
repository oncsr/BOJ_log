#include <bits/stdc++.h>
using namespace std;

int N, H, D, K, arr[18]{};

int ans = 0;

void solve(int hp, int dist, int pos, int used){
    if(pos >= N){
        ans = max(ans, hp);
        return;
    }
    // 1
    int hp1 = hp - max(0, (arr[pos] - dist) >> 1);
    solve(hp1, dist, pos+1, used);
    // 2
    int hp2 = hp - max(0, arr[pos] - dist - K);
    solve(hp2, dist+K, pos+1, used);
    // 3
    if(used)    return;
    hp -= max(0, arr[pos] - dist);
    pos += 2;
    used = 1;
    solve(hp, dist + K, pos, used);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>H>>D>>K;
    for(int i=0;i<N;i++)    cin>>arr[i];
    solve(H, D, 0, 0);

    cout<<(ans > 0 ? ans : -1);
    
}