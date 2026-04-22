#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > Tree(1001);

void dfs(int now, int parent, int distance, int dest) {
	if (now == dest) {
		cout << distance << '\n';
		return;
	}
	for (auto next : Tree[now]) {
		int child = next.first;
		int cost = next.second;
		if (child != parent) {
			dfs(child, now, distance + cost, dest);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Tree[a].push_back({ b,c });
		Tree[b].push_back({ a,c });
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dfs(a, 0, 0, b);
	}
}