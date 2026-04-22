#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	queue<ii> Q;
	Q.push({ 0,0 });
	int vis[1000001] = { 1 };
	while (!Q.empty()) {
		int now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		if (cnt <= K && now == N) {
			cout << "minigimbob";
			return 0;
		}
		int d1 = now + 1, d2 = now + now / 2;
		if (d1 <= N && !vis[d1]) {
			Q.push({ d1,cnt + 1 });
			vis[d1]++;
		}
		if (d2 <= N && !vis[d2]) {
			Q.push({ d2,cnt + 1 });
			vis[d2]++;
		}
	}
	cout << "water";
}