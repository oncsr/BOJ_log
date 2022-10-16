#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, d[1001]{}, a, b;
	cin >> N >> M;
	vector<vector<int> > V(1001);
	while (M--) {
		int n;
		cin >> n;
		cin >> a;
		for (int i = 0; i < n - 1; i++) {
			cin >> b;
			V[a].push_back(b);
			d[b]++;
			a = b;
		}
	}
	queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (!d[i])	Q.push(i);
	int res[1001]{}, idx = 0, s = 0;
	for (int i = 1; i <= N; i++) {
		if (Q.empty()) {
			cout << 0;
			s++;
			break;
		}
		int now = Q.front();
		Q.pop();
		res[idx++] = now;
		for (int j : V[now])
			if (!(--d[j]))
				Q.push(j);
	}
	if (!s)
		for (int i = 0; i < idx; i++)
			cout << res[i] << '\n';
}