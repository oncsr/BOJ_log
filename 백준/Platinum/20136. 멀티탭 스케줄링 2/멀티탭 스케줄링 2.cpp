#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int arr[500001]{};
	vector<vector<int>> EX(500001);
	vector<int> pos(500001);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		EX[arr[i]].push_back(i);
	}
	for (int i = 1; i <= K; i++)	EX[i].push_back(K + 1);

	int use[500001]{}, cnt = 0;
	int ans = 0;
	priority_queue<pair<int, int>> Q;
	for (int i = 1; i <= K; i++) {
		int to = arr[i];
		if (use[to]) {
			pos[to]++;
			Q.push({ EX[to][pos[to]], to });
			continue;
		}

		if (cnt < N) {
			pos[to]++;
			use[to] = 1;
			cnt++;
			Q.push({ EX[to][pos[to]], to });
			continue;
		}

		int fr = Q.top().second, wit = Q.top().first;
		Q.pop();
		use[to] = 1;
		use[fr] = 0;
		pos[to]++;
		Q.push({ EX[to][pos[to]], to });
		ans++;
	}
	cout << ans;

}