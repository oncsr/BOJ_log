#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(501);
vector<int> visit(501);

int cnt = 0;

int dfs(int n, int p) {
	visit[n]++;
	int t = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		if (visit[i])	return 0;
		t &= dfs(i, n);
	}
	return t;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, b, T = 1;
	cin >> N >> M;
	while (N || M) {
		V = vector<vector<int> >(501);
		visit = vector<int>(501);
		cnt = 0;
		for (; M--;) {
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i])	cnt += dfs(i, 0);
		}
		cout << "Case " << T++ << ": ";
		if (!cnt)	cout << "No trees.\n";
		else if (cnt == 1)	cout << "There is one tree.\n";
		else	cout << "A forest of " << cnt << " trees.\n";
		cin >> N >> M;
	}
}