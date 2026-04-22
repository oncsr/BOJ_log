#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int k, ans = -1;
		cin >> k;
		int visit[4000001]{};
		visit[1]++;
		queue<pair<int, int> > Q;
		Q.push({ 1,0 });
		while (!Q.empty()) {
			int now = Q.front().first;
			int step = Q.front().second;
			Q.pop();
			if (now == k) {
				ans = step;
				break;
			}
			if (now - 1 > 0 && !visit[now - 1]) {
				Q.push({ now - 1,step + 1 });
				visit[now - 1]++;
			}
			if (now * 2 <= min(k * 2, 4000000) && !visit[now * 2]) {
				Q.push({ now * 2, step + 1 });
				visit[now * 2]++;
			}
		}
		cout << ans << '\n';
	}
}