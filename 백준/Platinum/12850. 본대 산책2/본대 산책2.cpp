#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

const ll MOD = 1'000'000'007;
matrix base = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,0,1},
    {0,0,0,1,1,0,1,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,1,0,1,0}
};

matrix multiply(matrix &a, matrix &b) {
    matrix ret = vector<vector<ll>>(8, vector<ll>(8));
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) {
        for(int k=0;k<8;k++) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    }
    return ret;
}

matrix power(int k) {
    if(k == 1) return base;
    matrix half = power(k>>1);
    matrix ret = multiply(half, half);
    if(k&1) ret = multiply(ret, base);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll D;
    cin>>D;
    cout<<power(D)[0][0];

}