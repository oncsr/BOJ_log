#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int N;
vector<vector<ii> > V(100001);
int cnt = 0;
int idx = 0;

int dfs(int node, int dist, int *visit) {
	if (V[node].empty()) {
		if (dist > cnt) {
			cnt = dist;
			idx = node;
		}
	}
	else {
		visit[node]++;
		if (dist > cnt) {
			cnt = dist;
			idx = node;
		}
		for (int i = 0; i < V[node].size(); i++) {
			if (!visit[V[node][i].first])
				dfs(V[node][i].first, V[node][i].second + dist, visit);
		}
		return idx;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		int a, b;
		cin >> a;
		while (a != -1) {
			cin >> b;
			V[n].push_back({ a,b });
			cin >> a;
		}
	}
	int arr[100001] = { 0 };
	int id = dfs(1, 0, arr);
	int arr2[100001] = { 0 };
	dfs(id, 0, arr2);
	cout << cnt << '\n';
}