#include <iostream>
#include <vector>
using namespace std;

vector<int> visit(101);
vector<vector<int> > V(101);

void dfs(int n, int p) {
	for (int i : V[n]) {
		if (i != p) {
			visit[i]++;
			dfs(i, n);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		visit = vector<int>(101);
		visit[i]++;
		dfs(i, 0);
		bool f = 0;
		for (int j = 1; j <= N; j++) {
			if (!visit[j])	f = 1;
		}
		if (!f) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}