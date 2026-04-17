#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    for(cin>>T;T--;){
        int arr[1001]{};
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)   cin>>arr[i];
        int vis[1001]{};
        int ans = 0;
        for(int i=1;i<=N;i++){
            if(vis[i])  continue;
            ans++;
            vis[i]++;
            int g = arr[i];
            while(!vis[g]){
                vis[g]++;
                g = arr[g];
            }
        }
        cout<<ans<<'\n';
    }

}