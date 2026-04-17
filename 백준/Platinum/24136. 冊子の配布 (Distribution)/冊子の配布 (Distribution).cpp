#include <bits/stdc++.h>
using namespace std;

int sum[10001]{}, chk[10001]{}, par[10001]{}, arr[10001]{};
vector<vector<int>> V(10001);

int mx = 0, x = 0;

void pre(int n, int p) {
	for (int i : V[n]) {
		if (i == p)	continue;
		sum[i] += sum[n];
		pre(i, n);
	}
}

void dfs(int n, int p, int m, int q) {
	if (chk[n] == q)	m += arr[n];
	sum[n] -= m;
	if (sum[n] > mx)	mx = sum[n], x = n;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n, m, q);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(i);
		arr[i] = b;
		sum[i] = b;
		par[i] = a;
	}
	pre(1, 0);
	int ans = 0;
	for (int q = 1; q <= M; q++) {
		mx = 0;
		dfs(1, 0, 0, q);
		ans += mx;
		while (x) {
			if (!chk[x])	chk[x] = q + 1;
			x = par[x];
		}
	}
	cout << ans;

}