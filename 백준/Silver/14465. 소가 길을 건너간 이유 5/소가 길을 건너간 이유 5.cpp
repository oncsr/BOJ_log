#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K, B, arr[100001]{};
    for(cin>>N>>K>>B;B--;){
        int a;
        cin>>a;
        arr[a]++;
    }
    int ans = N;
    for(int i=1;i<=N;i++){
        arr[i] += arr[i-1];
        if(i >= K)  ans = min(ans, arr[i] - arr[i-K]);
    }
    cout<<ans;

}