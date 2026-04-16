#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	
	ll N;
	int dp[100001][500]{}, mod = 1e9+7;
	cin>>N;
	string S;
	cin>>S;

	dp[1][0] = 1;
	ll ans = 0;
	for(ll k=0;(k+1)*(k+2)/2 - 1<=N+1;k++){
		for(ll n=1;n<=N;n++){
			if(S[n-1] == '#')	continue;
			int &v = dp[n][k];
			if(n-1 >= 1)	v = (dp[n-1][k] + v) % mod;
			if(k && n-k-1 >= 1)	v = (dp[n-k-1][k-1] + v) % mod;
		}
		ans = (ans + dp[N][k]) % mod;
		for(int i=N-k-1;i<=N;i++)	ans = (ans + dp[i][k]) % mod;
	}

	cout << ans % mod;

}