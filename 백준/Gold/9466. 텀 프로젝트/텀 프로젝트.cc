#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > V(100001);
vector<pair<int, int> > visit(100001);
vector<int> d(100001);
int cnt = 0, idx = 0;

int dfs(int n, int p, int s) {
	visit[n] = { 1,idx };
	d[n] = s;
	for (int i : V[n]) {
		if (i == n) {
			return 1;
		}
		else if (visit[i].first && visit[i].second == idx) {
			return s - d[i] + 1;
		}
		else if (visit[i].first && visit[i].second != idx)
			return 0;
		else if (!visit[i].first) {
			return dfs(i, n, s + 1);
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N, a;
		idx = 0;
		cin >> N;
		V = vector<vector<int> >(N + 1);
		cnt = N;
		visit = vector<pair<int, int> >(N + 1);
		d = vector<int>(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> a;
			V[i].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i].first) {
				cnt -= dfs(i, 0, 1);
				idx++;
			}
		}
		cout << cnt << '\n';
	}
}