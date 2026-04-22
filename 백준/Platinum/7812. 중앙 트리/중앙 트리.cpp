#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, ll>;

int N;
vector<vector<ii>> V(10000);
vector<ll> D(10000);
vector<ll> sb(10000);

ll dfs(int n, int p) {
	sb[n] = 1;
	for (ii i : V[n]) {
		if (i.first == p)	continue;
		ll g = dfs(i.first, n);
		sb[n] += sb[i.first];
		D[n] += g + i.second * sb[i.first];
	}
	return D[n];
}

void dfs2(int n, int p) {
	for (ii i : V[n]) {
		if (i.first == p)	continue;
		ll down = D[i.first] + i.second * sb[i.first];
		D[i.first] += D[n] - down + i.second * (N - sb[i.first]);
		dfs2(i.first, n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> N; N; cin >> N) {
		V = vector<vector<ii>>(N);
		D = vector<ll>(N);
		sb = vector<ll>(N);
		for (int i = 1; i < N; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			V[a].push_back({ b,c });
			V[b].push_back({ a,c });
		}
		dfs(0, -1);	dfs2(0, -1);
		ll mn = 1e18;
		for (int i = 0; i < N; i++)	mn = min(mn, D[i]);
		cout << mn << '\n';
	}
}