#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 1000000; j += i)
				if (!e[j])	e[j] = i;
	
	ll diff[1000001]{};
	for (int i = 2; i <= 1000000; i++) {
		ll T = i;
		ll ans = 1;
		ll temp = e[T], cnt = 0;
		while (e[T]) {
			if (temp != e[T]) {
				ll v = 1;
				for (int j = 0; j < cnt + 1; j++)	v *= temp;
				ans *= (v - 1) / (temp - 1);
				cnt = 0;
			}
			temp = e[T];
			cnt++;
			T /= e[T];
		}
		if (T > 1) {
			if (temp == T)	cnt++;
			ll v = 1;
			for (int j = 0; j < cnt + 1; j++)	v *= temp;
			ans *= (v - 1) / (temp - 1);
			if (temp != T)	ans *= (T * T - 1) / (T - 1);
		}
		diff[i] = abs(ans - (ll)i * 2);
	}

	int S, E, B, tc = 0;
	for (cin >> S >> E >> B; S || E || B; cin >> S >> E >> B) {
		int ans = 0;
		for (int i = S; i <= E; i++) {
			if (diff[i] <= B)	ans++;
		}
		cout << "Test " << ++tc << ": " << ans << '\n';
	}
}