#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sub[200001]{}, arr[200001]{};
vector<vector<int>> V(200001);

ll dfs(int n){
    sub[n] = 1;
    for(int i:V[n]) sub[n] += dfs(i);
    arr[n] = sub[n];
    for(int i:V[n]) arr[n] += sub[i] * (sub[n] - sub[i]);
    return sub[n];
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);

    int N, R;
    cin>>N;
    for(int i=1;i<=N;i++){
        int p;
        cin>>p;
        if(p)   V[p].push_back(i);
        else    R = i;
    }

    dfs(R);
    ll odd = 0, even = 0, turn = 1;
    for(ll i=1;i<=N;i++){
        if(!(arr[i]&1)) odd += i * (arr[i] / 2), even += i * (arr[i] / 2);
        else{
            if(turn&1)  odd += i * ((arr[i] + 1) / 2), even += i * (arr[i] / 2);
            else    odd += i * (arr[i] / 2), even += i * ((arr[i] + 1) / 2);
            turn ^= 1;
        }
    }
    cout<<even<<' '<<odd;

}