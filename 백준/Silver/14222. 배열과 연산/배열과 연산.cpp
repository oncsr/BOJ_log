#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k, cnt[51]{};
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    int v = 0;
    for(int i=1;i<=n;i++){
        while(cnt[i] > 1){
            int g = i;
            while(g <= n && cnt[g]) g += k;
            if(g <= n)  cnt[g]++, cnt[i]--;
            else    break;
        }
        if(cnt[i])  v++;
    }
    cout<<(int)(v==n);

}