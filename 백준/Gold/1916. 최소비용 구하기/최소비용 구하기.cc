#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, b, c, start, end;
	cin >> N;
	int d[1001]{};
	for (int i = 1; i <= N; i++)	d[i] = -1;
	vector<vector<ii> > G(1001);
	priority_queue<ii, vector<ii>, greater<> > Q;
	for (cin >> M; M--;) {
		cin >> a >> b >> c;
		G[a].push_back({ b,c });
	}
	cin >> start >> end;
	d[start] = 0;
	Q.push({ 0, start });
	while (!Q.empty()) {
		int dist = Q.top().first;
		int now = Q.top().second;
		Q.pop();
		if (dist > d[now])	continue;
		for (ii next : G[now]) {
			if (d[next.first] == -1 || d[next.first] > dist + next.second) {
				d[next.first] = dist + next.second;
				Q.push({ d[next.first], next.first });
			}
		}
	}
	cout << d[end];
}