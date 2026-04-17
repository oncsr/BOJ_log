#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll cnt[2000001]{}, N;
	cin >> N;
	ll ans = N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for (int j = 1; j * j <= a; j++) {
			if (a % j)	continue;
			cnt[a / j]++;
			if (j != a / j)	cnt[j]++;
		}
	}
	for (int i = 1; i <= 2000000; i++) {
		if (cnt[i] < 2)	continue;
		ans = max(ans, cnt[i] * i);
	}
	cout << ans;

}