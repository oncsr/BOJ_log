#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<set<int>> cc;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	cc.resize(N + 1);
	
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		cc[b].insert(a);
		if (cc[a].count(b)) {
			cc[a].erase(b);
			cc[b].erase(a);
		}
	}

	int max_size = -1, node = 0;
	for (int i = 1; i <= N; i++) {
		if ((int)cc[i].size() > max_size) {
			max_size = cc[i].size();
			node = i;
		}
	}
	cout << node << ' ' << max_size;

}