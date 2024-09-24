#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll K, H, Q, v = 1;
	cin >> K >> H >> Q;

	for (int i = 1; i < H; i++) {
		if (v > 1e18)	break;
		v *= (K + 1);
	}

	for (; Q--;) {
		ll a, b;
		cin >> a >> b;
		if ((b + 1) % (K + 1) == 0) {
			if (v < (b + 1) / (K + 1)) { cout << "-1\n"; continue; }
		}
		else {
			if (v <= (b + 1) / (K + 1)) { cout << "-1\n"; continue; }
		}
		if (a == b) { cout << "0\n"; continue; }
		vector<int> routeA, routeB;
		ll k = v;
		while (a % k) {
			routeA.push_back(a / k);
			a %= k;
			k /= (K + 1);
		}
		k = v;
		while (b % k) {
			routeB.push_back(b / k);
			b %= k;
			k /= (K + 1);
		}

		int id = 0;
		while (id < min(routeA.size(), routeB.size()) && routeA[id] == routeB[id])	id++;
		cout << (routeA.size() - id + routeB.size() - id + 2) << '\n';
	}

}