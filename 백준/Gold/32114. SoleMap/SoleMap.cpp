#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, W[500001]{}, C[500001]{};
	cin >> N >> M;
	for (int i = 1; i < N; i++)	cin >> W[i];
	
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		C[a] += c;
		C[b] -= c;
	}
	int s = 0;
	for (int i = 1; i < N; i++) {
		s += C[i];
		C[i] = s;
		ll w = W[i], c = C[i], p = c % w, q = w - p;
		ll ans = (c / w) * (c / w) * q + (c / w + 1) * (c / w + 1) * p;
		cout << ans << '\n';
	}

}