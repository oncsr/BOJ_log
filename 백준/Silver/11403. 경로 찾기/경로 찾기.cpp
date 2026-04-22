#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, ans[101][101]{};
	vector<vector<int> > V(101);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			if (!a)	continue;
			V[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++) {
		queue<int> Q;
		int vis[101]{};
		Q.push(i);
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			for (int next : V[now]) {
				if (!vis[next]) {
					Q.push(next);
					vis[next]++;
					ans[i][next] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	cout << ans[i][j] << ' ';
		cout << '\n';
	}
}