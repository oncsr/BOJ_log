#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> V(100001);
ll arr[100001]{};
ll cnt[100001]{};

ll dfs(int n, int p) {
	ll sub = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		ll g = dfs(i, n);
		sub += g;
		cnt[i] = g * (N - g);
	}
	return sub;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 0; i < N - 1; i++)	cin >> arr[i];
	dfs(1, 0);
	sort(cnt, cnt + N + 1, greater<ll>());
	sort(arr, arr + N - 1, less<ll>());
	ll s = 0;
	for (int i = 0; i < N - 1; i++) {
		s = (s + arr[i] * cnt[i]) % 1000000007;
	}
	cout << s;
}