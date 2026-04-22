#include <iostream>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<ll, bool> vis;
	ll N;
	cin >> N;
	queue<pair<ll, int> > Q;
	Q.push({ N,0 });
	vis[N] = 1;
	while (!Q.empty()) {
		ll now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		if (now == 1) {
			cout << cnt;
			return 0;
		}
		if (now % 3 == 0 && !vis[now/3]) {
			Q.push({ now / 3,cnt + 1 });
			vis[now / 3] = 1;
		}
		if (now % 2 == 0 && !vis[now / 2]) {
			Q.push({ now / 2, cnt + 1 });
			vis[now / 2] = 1;
		}
		if (!vis[now - 1]) {
			Q.push({ now - 1, cnt + 1 });
			vis[now - 1] = 1;
		}
	}
}