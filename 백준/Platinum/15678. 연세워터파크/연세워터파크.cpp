#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pp = pair<ll, ll>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, D;
	cin >> N >> D;
	ll mx = -1000000001;
	priority_queue<pp> Q;
	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		if (i == 1) {
			Q.push({ a,i });
			mx = a;
			continue;
		}
		while (i - Q.top().second > D)	Q.pop();
		ll A = max(0LL, Q.top().first) + a;
		Q.push({ A, i });
		mx = max(mx, A);
	}
	cout << mx;
}