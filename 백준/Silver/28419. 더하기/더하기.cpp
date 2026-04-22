#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll s1 = 0, s2 = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (i & 1)	s1 += a;
		else	s2 += a;
	}
	cout << (n == 3 && s2 > s1 ? -1 : abs(s1 - s2));
}