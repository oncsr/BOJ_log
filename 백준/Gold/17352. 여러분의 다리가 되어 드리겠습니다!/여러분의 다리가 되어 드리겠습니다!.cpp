#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(300001);
int visit[300001]{};

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
	int n, d[300001]{}, a, b;
	cin >> n;
	for (int i = 2; i < n; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	visit[1]++;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cout << "1 " << i;
			return 0;
		}
	}
}