#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

const ll MOD = 1'000'000'007;
matrix base;
int N, M, D;

matrix multiply(matrix &a, matrix &b) {
    matrix ret = vector<vector<ll>>(a.size(), vector<ll>(b[0].size()));
    for(int i=0;i<ret.size();i++) for(int j=0;j<ret[i].size();j++) {
        for(int k=0;k<a[i].size();k++) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
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
    
    cin>>N>>M;
    base = matrix(N, vector<ll>(N));
    for(int a,b;M--;base[a-1][b-1] = base[b-1][a-1] = 1) cin>>a>>b;
    cin>>D;
    cout<<power(D)[0][0];

}