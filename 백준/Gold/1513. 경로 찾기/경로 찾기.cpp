#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, c, mod = 1'000'007;
	cin>>n>>m>>c;
	int dp[51][51][51][51]{}, arr[51][51]{};

	for(int i=0;i<c;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b] = i+1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i == 1 && j == 1){
				if(arr[i][j])	dp[1][1][1][arr[i][j]] = 1;
				else 	dp[1][1][0][0] = 1;
				continue;
			}
			for(int k=0;k<=c;k++){
				if(arr[i][j]){
					if(!k)	continue;
					for(int d=0;d<arr[i][j];d++)	dp[i][j][k][arr[i][j]] += dp[i-1][j][k-1][d] + dp[i][j-1][k-1][d];
					dp[i][j][k][arr[i][j]] %= mod;
				}
				else{
					for(int d=0;d<=c;d++){
						dp[i][j][k][d] = (dp[i-1][j][k][d] + dp[i][j-1][k][d]) % mod;
					}
				}
			}
		}
	}
	for(int k=0;k<=c;k++){
		int res = 0;
		for(int d=0;d<=c;d++){
			res += dp[n][m][k][d];
		}
		cout<<res%mod<<' ';
	}

}