#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > V(100001);
int cnt = 0;
void dfs(int n, int P, int r, int d) {
	if (n == d) {
		cnt = r;
		return;
	}
	for (pair<int, int> next : V[n])
		if (next.first != P)
			dfs(next.first, n, r + next.second, d);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, a, b, c;
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	for (; Q--;) {
		cin >> a >> b;
		dfs(a, 0, 0, b);
		cout << cnt << '\n';
		cnt = 0;
	}
}