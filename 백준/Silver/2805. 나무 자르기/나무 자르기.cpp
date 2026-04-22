#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ll M;
	cin >> N >> M;
	ll arr[1000000]{}, mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	ll s = 0, e = mx, m = (s + e + 1) / 2;
	while (s <= e) {
		ll cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += max(0LL, arr[i] - m);
		if (cnt >= M) {
			if (s == m)	break;
			s = m;
		}
		else {
			if (e == m - 1)	break;
			e = m - 1;
		}
		m = (s + e + 1) / 2;
	}
	cout << m;
}