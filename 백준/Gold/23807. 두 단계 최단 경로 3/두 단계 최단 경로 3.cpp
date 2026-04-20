#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, ll>;

vector<vector<ii>> V;
int N, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	V.resize(N + 1);
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	int x, z;
	cin >> x >> z;
	int p;
	cin >> p;
	int arr[101] = { x };
	for (int i = 1; i <= p; i++)	cin >> arr[i];

	vector<vector<ll>> D(N + 1, vector<ll>(p + 1, -1));
	for (int i = 0; i <= p; i++) {
		D[arr[i]][i] = 0;
		priority_queue<ii, vector<ii>, greater<>> Q;
		Q.push({ 0,arr[i] });
		while (!Q.empty()) {
			auto [dist, now] = Q.top();
			Q.pop();
			if (dist > D[now][i])	continue;
			for (auto [next, cost] : V[now]) {
				if (D[next][i] == -1 || D[next][i] > D[now][i] + cost) {
					D[next][i] = D[now][i] + cost;
					Q.push({ D[next][i], next});
				}
			}
		}
	}
	ll ans = 1e18;

	for (int a = 1; a <= p; a++) {
		if (D[arr[a]][0] == -1)	continue;
		for (int b = 1; b <= p; b++) {
			if (a == b || D[arr[b]][a] == -1)	continue;
			for (int c = 1; c <= p; c++) {
				if (a == c || b == c || D[arr[c]][b] == -1 || D[z][c] == -1)	continue;
				ans = min(ans, D[arr[a]][0] + D[arr[b]][a] + D[arr[c]][b] + D[z][c]);
			}
		}
	}

	cout << (ans == 1e18 ? -1 : ans);


}