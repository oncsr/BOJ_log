#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

array<int, 2> roadwork(string S){
    vector<int> d(S.size()+1);
    d[0] = 1, d[1] = 2;
    int cnt = 1, last = 0, p = 0, next_p = 0;
    for(int i=2;i<=S.size();i++){
        char now = S[i-1], prev = S[i-2];
        if(now == prev) {
            d[i] = d[i-1] + d[p];
            next_p = i-1;
        }
        else {
            if(i-1 > last) {
                p = next_p;
                cnt++, last = i;
                d[i] = d[p];
            }
            else{
                p++;
                d[i] = d[i-1] + d[p];
            }
        }
        d[i] %= mod;
    }
    return array<int, 2>{cnt,d[S.size()]};
}