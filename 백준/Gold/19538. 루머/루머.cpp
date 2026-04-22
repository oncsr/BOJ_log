#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N;
	vector<vector<int> > V(200001);
	int near[200001]{};
	for (int i = 1; i <= N; i++) {
		int a;
		for (cin >> a; a; cin >> a) {
			near[a]++;
			V[i].push_back(a);
		}
	}
	cin >> M;
	int near_rumor[200001]{};
	bool visit[200001]{};
	queue<pair<int, int> > Q;
	vector<int> ans(200001, -1);
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		ans[a] = 0;
		visit[a] = 1;
		Q.push({ a,0 });
	}
	while (!Q.empty()) {
		int now = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		ans[now] = time;
		for (int i : V[now])	if (!visit[i])	near_rumor[i]++;
		for (int i : V[now]) {
			if (!visit[i] && near_rumor[i] >= (near[i] + 1) / 2) {
				visit[i] = 1;
				Q.push({ i,time + 1 });
			}
		}
	}
	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';
}