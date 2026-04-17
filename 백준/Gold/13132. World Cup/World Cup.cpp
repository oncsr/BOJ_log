#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = unsigned long long;

int N;
ld M, B;
ld ans = 0;
pair<ld, ld> arr[10]{};
ll base = 1000000000LL;

void solve(int pos, ld prob, ll money) {
	if (pos == N) {
		if (money >= base)	ans += prob;
		return;
	}
	if (money <= base / 100 * B)	return;
	solve(pos + 1, prob * arr[pos].first, money + money / 100 * M * (arr[pos].second - 1.));
	solve(pos + 1, prob * (1. - arr[pos].first), money - money / 100 * M);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second, arr[i].first /= 100.;
	solve(0, 1., base);

	cout.precision(3);
	cout << fixed << ans * 100;

}