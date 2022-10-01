#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)	return a.second > b.second;
	return a.first > b.first;
}
int main() {
	pair<int, int> P[3];
	cin >> P[0].first >> P[1].first >> P[2].first;
	cin >> P[0].second >> P[1].second >> P[2].second;
	sort(P, P + 3, cmp);
	int p1 = P[0].first, x1 = P[0].second;
	int p2 = P[1].first, x2 = P[1].second;
	int p3 = P[2].first, x3 = P[2].second, i;
	bool find = false;
	if (x1 == x2 && x2 == x3)	cout << x1;
	else {
		for (i = 1; p1 * i + x1 <= p1*p2*p3; i++) {
			if ((p1 * i + x1) % p2 == x2 && (p1 * i + x1) % p3 == x3) {
				find = true;
				break;
			}
		}
		if (find)	cout << p1 * i + x1;
		else	cout << -1;
	}
}