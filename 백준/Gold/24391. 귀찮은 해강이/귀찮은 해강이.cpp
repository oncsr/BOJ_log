#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(100001);
vector<int> visit(100001);

void dfs(int n, int p, int id) {
	if (!V[n].empty()) {
		for (int now : V[n]) {
			if (!visit[now]) {
				visit[now] = id;
				dfs(now, n, id);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, a, b;
	for (cin >> n >> m; m--;) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	int id = 1;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = id;
			dfs(i, 0, id++);
		}
	}
	int s = 0, t;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!i)	t = a;
		else {
			if (visit[t] != visit[a])	s++;
			t = a;
		}
	}
	cout << s;
}