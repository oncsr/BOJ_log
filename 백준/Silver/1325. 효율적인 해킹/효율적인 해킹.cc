#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int> > V(10001);
int N, M;

bool compare(const pair<int, int> p1, const pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}

int bfs(int n) {
	int visit[10001] = { 0 };
	queue<int> Q;
	Q.push(n);
	visit[n]++;
	int cnt = 0;
	while (!Q.empty()) {
		int c = Q.front();
		Q.pop();
		for (int i = 0; i < V[c].size(); i++) {
			int g = V[c][i];
			if (!visit[g]) {
				Q.push(g);
				visit[g]++;
			}
		}
		cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[b].push_back(a);
	}
	vector<pair<int, int> > ans;
	for (int i = 1; i <= N; i++)
		ans.push_back({ bfs(i),i });
	sort(ans.begin(), ans.end(), compare);
	int mx = ans[0].first;
	for (int i = 0; i < N; i++) {
		if (mx == ans[i].first)
			cout << ans[i].second << ' ';
		else
			break;
	}
	cout << '\n';
}