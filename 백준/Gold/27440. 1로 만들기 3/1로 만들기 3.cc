#include <iostream>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	map<ll, int> M;
	queue<pair<ll, int> > Q;
	Q.push({ N,0 });
	while (!Q.empty()) {
		ll now = Q.front().first;
		int cnt = Q.front().second;
		if (now == 1) {
			cout << cnt;
			return 0;
		}
		Q.pop();
		if (now % 3 == 0) {
			if (!M[now / 3] || (M[now / 3] && M[now / 3] > cnt + 1)) {
				Q.push({ now / 3, cnt + 1 });
				M[now / 3] = cnt + 1;
			}
		}
		if (now % 2 == 0) {
			if (!M[now / 2] || (M[now / 2] && M[now / 2] > cnt + 1)) {
				Q.push({ now / 2, cnt + 1 });
				M[now / 2] = cnt + 1;
			}
		}
		if (!M[now - 1] || (M[now - 1] && M[now - 1] > cnt + 1)) {
			Q.push({ now - 1,cnt + 1 });
			M[now - 1] = cnt + 1;
		}
	}

}