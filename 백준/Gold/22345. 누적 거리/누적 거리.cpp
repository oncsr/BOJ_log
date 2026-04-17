#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll ax[200001]{}, a[200001]{}, N, Q;
	cin >> N >> Q;
	pair<ll, ll> arr[200001]{};
	for (int i = 1; i <= N; i++) {
		ll ai, xi;
		cin >> ai >> xi;
		arr[i] = { xi, ai };
	}
	sort(arr + 1, arr + N + 1);
	ll pos[200001]{};
	for (int i = 1; i <= N; i++) {
		pos[i] = arr[i].first;
		a[i] = a[i - 1] + arr[i].second;
		ax[i] = ax[i - 1] + arr[i].first * arr[i].second;
	}

	for (; Q--;) {
		ll x;
		cin >> x;
		int j = upper_bound(pos + 1, pos + N + 1, x) - pos;
		ll V = x * a[j - 1] - ax[j - 1] + (ax[N] - ax[j - 1] - x * (a[N] - a[j - 1]));
		cout << V << '\n';
	}

}