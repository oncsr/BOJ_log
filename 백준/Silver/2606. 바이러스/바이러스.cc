#include <iostream>
#include <vector>
using namespace std;


vector<vector<int> > V(101);
int visit[101]{}, N, M, a, b, ans = 0;
void dfs(int n, int p) {
	for (int i : V[n]) {
		if (i != p && !visit[i]) {
			visit[i]++;
			ans++;
			dfs(i, n);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (cin >> N >> M; M--;) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	visit[1]++;
	dfs(1, 0);
	cout << ans;
	
}