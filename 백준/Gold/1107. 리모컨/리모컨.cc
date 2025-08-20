#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, no[10]{};
    cin>>N>>M;
    int ans = abs(100 - N);
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        no[a] = 1;
    }
    for(int i=0;i<=1000000;i++){
        string s = to_string(i);
        bool ex = 0;
        for(char i:s)   ex |= no[i-'0'];
        if(ex)  continue;
        ans = min(ans, abs(i-N) + (int)s.size());
    }
    cout<<ans;

}