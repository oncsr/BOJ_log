#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll S, T, D;
	cin >> S >> T >> D;
	ll s[100001]{}, mn = 1e18, id = 0;
	for (int i = 1; i <= D; i++) {
		cin >> s[i], s[i] += s[i - 1];
		if (s[i] < mn)	mn = s[i], id = i;
	}
	if (S + mn <= T) {
		for (int i = 1; i <= D; i++) {
			if (S + s[i] <= T)	return cout << i, 0;
		}
	}
	if (s[D] >= 0)	return cout << -1, 0;
	
	ll p = (T - S - mn + 1) / s[D] + 1;
	S += p * s[D];
	for (int i = 1; i <= D; i++) {
		if (S + s[i] <= T)	return cout << p * D + i, 0;
	}

}