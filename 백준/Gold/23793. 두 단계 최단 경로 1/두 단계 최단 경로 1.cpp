#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<vector<ii>> V;
int N, M;

int dijk(int s, int e) {
	vector<int> D(N + 1, -1);
	D[s] = 0;
	priority_queue<ii, vector<ii>, greater<>> Q;
	Q.push({ 0,s });
	while (!Q.empty()) {
		auto [dist, now] = Q.top();
		Q.pop();
		if (dist > D[now])	continue;
		for (auto [next, cost] : V[now]) {
			if (D[next] == -1 || D[next] > D[now] + cost) {
				D[next] = D[now] + cost;
				Q.push({ D[next], next });
			}
		}
	}
	return D[e];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	V.resize(N + 1);
	vector<tuple<int, int, int>> E;
	vector<tuple<int, int, int>> R;
	for (int i = M; i--;) {
		int a, b, c;
		cin >> a >> b >> c;
		R.push_back({ a,b,c });
	}
	int x, y, z;
	cin >> x >> y >> z;
	for (auto [a, b, c] : R) {
		if (a == y || b == y)	E.push_back({ a,b,c });
		else	V[a].push_back({ b,c });
	}
	int sec = dijk(x, z);
	for (auto [a, b, c] : E)	V[a].push_back({ b,c });
	int fir1 = dijk(x, y), fir2 = dijk(y, z);
	if (fir1 == -1 || fir2 == -1)	cout << -1 << ' ';
	else	cout << fir1 + fir2 << ' ';
	cout << sec;

	

}