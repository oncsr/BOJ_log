#include <iostream>
#include <algorithm>
using namespace std;

int R(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	int N;
	for (cin >> N; N--;) {
		pair<int, int> P[4]{};
		for (int i = 0; i < 4; i++)	cin >> P[i].first >> P[i].second;
		sort(P, P + 4);
		int d1 = R(P[0], P[1]);
		int d2 = R(P[0], P[2]);
		int d3 = R(P[1], P[3]);
		int d4 = R(P[2], P[3]);
		bool c = (d1 == d2 && d2 == d3 && d3 == d4);
		if (P[0].first == P[1].first) {
			bool c1 = P[2].first == P[3].first;
			bool c2 = P[0].first != P[2].first;
			bool c3 = P[0].second == P[2].second;
			c &= (c1 & c2 & c3);
		}
		else {
			int d5 = R(P[0], P[3]);
			int d6 = R(P[1], P[2]);
			bool c1 = (d5 == d6);
			c &= c1;
		}
		cout << c << '\n';
	}
}