#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<ll, bool> M;
	vector<ll> V;
	ll x, N;
	cin >> x >> N;
	while (!M[x]) {
		M[x] = true;
		V.push_back(x);
		if (x % 2LL)	x = (2 * x) ^ 6LL;
		else	x = (x / 2) ^ 6LL;
	}
	ll sz = V.size(), sx;
	for (int i = 0; i < sz; i++) {
		if (V[i] == x) {
			sx = i;
			break;
		}
	}
	if (N < sx)	cout << V[N];
	else {
		cout << V[sx + (N - sx) % (sz - sx)];
	}
}