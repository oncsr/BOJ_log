#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	ll x[100001]{}, v[100001]{}, cur = 0, mx = 0, ans = 1, s = 0;
	for (int i = 0; i < N; i++) {
		ll m, p, d;
		cin >> m >> p >> d;
		s += p;
		v[d] -= p;
		x[d] -= m + p * d;
		x[1] += m;
	}

	for (int i = 1; i <= 100000; i++) {
		cur += s + x[i];
		s += v[i];
		if (cur > mx)	mx = cur, ans = i;
	}
	cout << ans;

}