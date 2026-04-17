#include <bits/stdc++.h>
using namespace std;

int dp[11][66][1024]{};
bool re[11][66][1024]{};

int sol(int k, int n, int m, int c){
    if(re[k][n][m]) return dp[k][n][m];
    dp[k][n][m] = (c+1) & 1;
    if(!n){
        re[k][n][m] = 1;
        return dp[k][n][m];
    }
    for(int i=0;i<k;i++){
        if(m & (1<<i))   continue;
        int res = sol(k, max(0,n-(i+1)), m | (1<<i), c+1);
        if(c & 1)   dp[k][n][m] |= res;
        else    dp[k][n][m] &= res;
    }
    re[k][n][m] = 1;
    return dp[k][n][m];

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int k=2;k<=10;k++){
        for(int i=1;i<=k*(k+1)/2;i++)   sol(k,i,0,0);
    }
    int Q;
    for(cin>>Q;Q--;){
        int a,b,k;
        cin>>a>>b>>k;
        if(k == 1){
            cout<<(((b-a)&1) ? "swoon\n" : "raararaara\n");
            continue;
        }
        int g = k*(k+1)/2, p = (b-a-1)/g;
        int n = b - (a+p*g);
        bool f = (k&1) && (p&1);
        cout<<((sol(k,n,0,0) ^ f) ? "raararaara\n" : "swoon\n");
    }
    
}