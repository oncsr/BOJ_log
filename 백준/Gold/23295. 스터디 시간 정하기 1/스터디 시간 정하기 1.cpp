#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, T;
	cin >> N >> T;
	ll S[100001]{}, p[100001]{};
	for (int i = 0; i < N; i++) {
		int k;
		for (cin >> k; k--;) {
			int a, b;
			cin >> a >> b;
			p[a]++;
			p[b]--;
		}
	}

	ll c = p[0];
	for (int i = 1; i <= 100000; i++) {
		S[i] += S[i - 1] + c;
		c += p[i];
	}

	ll mx = 0, ans = 0;
	for (int i = T; i <= 100000; i++) {
		if (S[i] - S[i - T] > mx)	mx = S[i] - S[i - T], ans = i - T;
	}
	cout << ans << ' ' << ans + T;


}