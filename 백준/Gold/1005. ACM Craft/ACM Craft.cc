#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N, K, r[1001]{}, a, b, deg[1001]{}, des, d[1001]{};
		vector<vector<int> > V(1001);
		cin >> N >> K;
		for (int i = 1; i <= N; i++)	cin >> r[i];
		while (K--) {
			cin >> a >> b;
			V[a].push_back(b);
			deg[b]++;
		}
		cin >> des;

		queue<int> Q;
		for (int i = 1; i <= N; i++)
			if (!deg[i]) {
				Q.push(i);
				d[i] = r[i];
			}
		for (int i = 1; i <= N; i++) {
			int now = Q.front();
			Q.pop();
			for (int j : V[now]) {
				d[j] = max(d[j], d[now] + r[j]);
				if (!(--deg[j])) {
					Q.push(j);
				}
			}
		}
		cout << d[des] << '\n';
	}
}