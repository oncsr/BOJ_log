#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, Q;
    cin>>N>>Q;
    int ans[100001]{}, rem[100001]{}, root[100002]{};
    iota(root, root+N+2, 0);
    
    function<int(int)> find = [&](int x) -> int {
        if(x == root[x])    return x;
        return root[x] = find(root[x]);
    };
    
    for(int i=1;i<=N;i++)   cin>>rem[i];
    for(;Q--;){
        int o, i, x;
        cin>>o>>i;
        if(o == 1){
            cin>>x;
            while(i <= N && x > 0){
                i = find(i);
                if(i > N)   break;
                int dr = min(rem[i], x);
                rem[i] -= dr, ans[i] += dr, x -= dr;
                if(!rem[i]){
                    root[i] = find(i+1);
                }
            }
        }
        else{
            cout<<ans[i]<<'\n';
        }
    }
}