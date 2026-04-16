#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<tuple<int, int, int>> V;
	for (int i = 0, l, h, r; i < N; i++) {
		cin >> l >> h >> r;
		V.emplace_back(l, h, i);
		V.emplace_back(r, h, i);
	}
	sort(V.begin(), V.end());

	int prev = -1;
	bitset<100000> on;
	priority_queue<pair<int, int>> Q;
	for (int i = 0; i < V.size();) {
		int x = get<0>(V[i]);
		while (i < V.size() && get<0>(V[i]) == x) {
			auto[a, b, c] = V[i];
			on[c].flip();
			if (on[c]) Q.emplace(b, c);
			i++;
		}
		while (!Q.empty() && !on[Q.top().second]) Q.pop();
		int v = Q.empty() ? 0 : Q.top().first;
		if (prev != v) cout << x << ' ' << v << ' ';
		prev = v;
	}

}