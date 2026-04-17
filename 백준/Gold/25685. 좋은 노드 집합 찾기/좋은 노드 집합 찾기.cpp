#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> V;
vector<ll> arr;
vector<pair<ll, ll>> dp;

void dfs(int n) {
	dp[n].first = arr[n];
	int child = 0, sel = 0, id = 0;
	ll mx = -1e18;
	for (int i : V[n]) {
		dfs(i);
		child++;
		dp[n].first += dp[i].second;
		if (dp[i].first >= dp[i].second) {
			dp[n].second += dp[i].first;
			sel++;
		}
		else {
			ll val = dp[i].first - dp[i].second;
			if (val > mx)	mx = val, id = i;
			dp[n].second += dp[i].second;
		}
	}
	if (child && !sel)	dp[n].second += mx;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		V = vector<vector<int>>(n + 1);
		arr = vector<ll>(n + 1);
		dp = vector<pair<ll, ll>>(n + 1);
		int root;
		for (int i = 1; i <= n; i++)	cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			if (!a)	root = i;
			else	V[a].push_back(i);
		}
		dfs(root);
		cout << max(dp[root].first, dp[root].second) << '\n';
	}

}