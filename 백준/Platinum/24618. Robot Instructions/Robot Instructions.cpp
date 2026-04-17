#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<ll, ll>>> res1(21);
vector<vector<pair<ll, ll>>> res2(22);
int N, X, Y;
vector<pair<ll, ll>> arr(40);

void cal1(int pos, ll x, ll y, ll c) {
	if (pos == N / 2) {
		res1[c].emplace_back(x, y);
		return;
	}
	cal1(pos + 1, x, y, c);
	cal1(pos + 1, x + arr[pos].first, y + arr[pos].second, c + 1);
}

void cal2(int pos, ll x, ll y, ll c) {
	if (pos == N) {
		res2[c].emplace_back(x, y);
		return;
	}
	cal2(pos + 1, x, y, c);
	cal2(pos + 1, x + arr[pos].first, y + arr[pos].second, c + 1);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> X >> Y;
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second;
	cal1(0, 0, 0, 0);
	cal2(N / 2, 0, 0, 0);
	for (auto& V : res2)	sort(V.begin(), V.end());

	for (int k = 1; k <= N; k++) {
		ll ans = 0;
		for (int i = max(k - 20, 0); i <= min(k, N / 2); i++) {
			int j = k - i;
			for (auto& [a, b] : res1[i]) {
				pair<ll, ll> t = { X - a, Y - b };
				ans += upper_bound(res2[j].begin(), res2[j].end(), t) - lower_bound(res2[j].begin(), res2[j].end(), t);
			}
		}
		cout << ans << '\n';
	}

}