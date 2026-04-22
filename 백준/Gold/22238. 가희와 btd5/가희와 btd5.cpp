#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

/*
 < 2022.03.29 >
 [used algorithm]
 > euclidean algorithm, map, priority queue, simulation
 [point]

*/

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	ll x, y;
	vector<ll> V;
	for (int i = 0; i < N; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		V.push_back(c);
		if (!i) {
			if (a != 0 && b != 0) {
				ll g = gcd(abs(a), abs(b));
				a /= g, b /= g;
			}
			else {
				if (a == 0)	b = (b > 0 ? 1 : -1);
				else	a = (a > 0 ? 1 : -1);
			}
			x = a, y = b;
		}
	}
	sort(V.begin(), V.end());
	ll s = 0;
	int id = 0;
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a != 0 && b != 0) {
			ll g = gcd(abs(a), abs(b));
			a /= g, b /= g;
		}
		else {
			if (a == 0)	b = (b > 0 ? 1 : -1);
			else	a = (a > 0 ? 1 : -1);
		}
		if (!(x == a && y == b)) {
			cout << N - id << '\n';
			continue;
		}
		s += c;
		while (id < N && V[id] <= s)	id++;
		cout << N - id << '\n';
	}
	
}