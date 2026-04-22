#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int K;
	ll N, a, mx = 0, arr[10000]{};
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> a;
		arr[i] = a;
		mx = max(mx, a);
	}
	ll s = 0, e = mx, m = (s + e + 1) / 2;
	while (s <= e) {
		ll cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += arr[i] / m;
		if (cnt >= N) {
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