#include <iostream>
#include <queue>
using namespace std;

int N, M, T, a, b;
vector<vector<int> > V;
vector<int> visit;

bool dfs(int n, int c) {
	visit[n] = c;
	bool temp = true;
	for (int i : V[n]) {
		if (visit[i] == c)	return false;
		if (!visit[i])	temp &= dfs(i, c == 2 ? 1 : 2);
	}
	return temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> T; T--;) {
		cin >> N >> M;
		V = vector<vector<int> >(N + 1);
		visit = vector<int>(N + 1, 0);
		for (; M--;) {
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		bool ans = true;
		for (int i = 1; i <= N; i++) {
			if (!visit[i])	ans &= dfs(i, 1);
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}