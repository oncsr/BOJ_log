#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	int cost[10][10]{};

	cin >> N >> M;
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!cost[a][b])	cost[a][b] = c;
		else	cost[a][b] = max(cost[a][b], c);
	}

	int ans = -1;
	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 1);

	do {
		
		int res = 0;
		bool fail = 0;
		for (int i = 0; i < N; i++) {
			int now = i == 0 ? 0 : ord[i - 1];
			int next = ord[i];
			if (!cost[now][next]) { fail = 1; break; }
			res += cost[now][next];
		}
		if (!cost[ord.back()][0])	fail = 1;
		if (fail)	continue;
		res += cost[ord.back()][0];
		ans = max(ans, res);

	} while (next_permutation(ord.begin(), ord.end()));

	cout << ans;

}