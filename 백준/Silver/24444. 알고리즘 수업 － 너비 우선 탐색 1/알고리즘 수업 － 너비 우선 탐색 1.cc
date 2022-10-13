#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, R, a, b, c = 0;
	cin >> N >> M >> R;
	vector<vector<int> > V(100001);
	queue<int> Q;
	int visit[100001]{}, ord[100001]{};
	for (; M--;) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)	sort(V[i].begin(), V[i].end());
	Q.push(R);
	visit[R]++;
	while (!Q.empty()) {
		int x = Q.front();
		ord[x] = ++c;
		Q.pop();
		for (int i : V[x])
			if (!visit[i]) {
				Q.push(i);
				visit[i]++;
			}
	}
	for (int i = 1; i <= N; i++)	cout << ord[i] << '\n';
}