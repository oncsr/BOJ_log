#include <iostream>
#include <algorithm>
using namespace std;
using ll = int;

ll R(pair<ll, ll> a, pair<ll, ll> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	int N;
	for (cin >> N; N--;) {
		pair<ll, ll> P[4]{};
		for (int i = 0; i < 4; i++)	cin >> P[i].first >> P[i].second;
		sort(P, P + 4);
		ll d1 = R(P[0], P[1]);
		ll d2 = R(P[0], P[2]);
		ll d3 = R(P[1], P[3]);
		ll d4 = R(P[2], P[3]);
		bool c = (d1 == d2 && d2 == d3 && d3 == d4);
		if (P[0].first == P[1].first) {
			bool c1 = P[2].first == P[3].first;
			bool c2 = P[0].first != P[2].first;
			bool c3 = P[0].second == P[2].second;
			c &= (c1 & c2 & c3);
		}
		else {
			ll d5 = R(P[0], P[3]);
			ll d6 = R(P[1], P[2]);
			bool c1 = (d5 == d6);
			c &= c1;
		}
		cout << c << '\n';
	}
}