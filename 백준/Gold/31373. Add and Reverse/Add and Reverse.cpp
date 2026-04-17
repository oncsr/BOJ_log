#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N;
	cin >> N;
	if (N < (1LL << 16)) { cout << N; return 0; }
	ll ans = N & ((1LL << 16) - 1);
	for (int i = 16; i < 32; i++) {
		if (!(N & (1LL << i)))	continue;
		ans += (1LL << (31 - i));
	}
	cout << ans + 1;

}
