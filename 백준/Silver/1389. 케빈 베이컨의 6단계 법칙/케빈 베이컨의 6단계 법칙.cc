#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];

pair<int, int> bfs(int n) {
	int visit[101] = { 0 };
	queue<pair<int, int> > Q;
	Q.push({ n,0 });
	visit[n]++;
	int lev = 0;
	int cnt = 0;
	while (!Q.empty()) {
		int c = Q.front().first;
		lev = Q.front().second;
		cnt += lev;
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && arr[c][i] == 1) {
				Q.push({ i,lev + 1 });
				visit[i]++;
			}
		}
	}
	return { n,cnt };
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int mn = 10000, ans;
	for (int i = 1; i <= N; i++) {
		pair<int, int> P = bfs(i);
		if (P.second < mn) {
			mn = P.second;
			ans = P.first;
		}
	}
	cout << ans << '\n';
}