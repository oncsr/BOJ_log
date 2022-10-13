#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
vector<vector<int> > V(100001);
int ord[100001]{}, N, M, R, c = 0, a, b, visit[100001]{};

void dfs(int n, int p) {
	visit[n]++;
	ord[n] = ++c;
	for (int i : V[n])
		if (i != p && !visit[i])
			dfs(i, n);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> R;
	for (; M--;) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		if(!V[i].empty())
			sort(V[i].begin(), V[i].end(), cmp);
	dfs(R, 0);
	for (int i = 1; i <= N; i++)	cout << ord[i] << '\n';
}