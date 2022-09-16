#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int N;
vector<vector<ii> > V(10001);
int cnt = 0;

int dfs(int node, int dist, int *visit) {
	if (V[node].empty())	cnt = max(cnt, dist);
	else {
		visit[node]++;
		cnt = max(cnt, dist);
		for (int i = 0; i < V[node].size(); i++) {
			if (!visit[V[node][i].first])
				dfs(V[node][i].first, V[node][i].second + dist, visit);
		}
		return cnt;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	int mx = 0;
	if(N != 1)
		for (int i = 1; i <= N; i++) {
			int arr[10001] = { 0 };
			int g = dfs(i, 0, arr);
			mx = max(mx, g);
		}
	cout << mx << '\n';
}