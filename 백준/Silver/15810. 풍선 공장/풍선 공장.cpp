#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M, arr[1000001]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	ll s = 0, e = 1000000000000, m = (s + e) >> 1;
	while (s < e) {
		ll cnt = 0;
		for (int i = 1; i <= N; i++)	cnt += m / arr[i];
		if (cnt >= M)	e = m;
		else	s = m + 1;
		m = (s + e) >> 1;
	}
	cout << m;

}