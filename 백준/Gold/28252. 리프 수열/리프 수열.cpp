#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, p, n;
	cin >> N >> p;
	int par = 1 + p, now = 1;
	vector<pair<int, int> > V;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (a > p) {
			cout << -1;
			return 0;
		}
		if (a == p && a == 1) {
			cout << -1;
			return 0;
		}
		for (int j = 0; j < a - 1; j++)	V.push_back({ now++,par++ });
		for (int j = 0; j < p - a + 1; j++)	V.push_back({ now++,par });
		par++;
		p = a;
	}
	if (p > 2) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < p - 1; i++)	V.push_back({ now + i, par - 1 });
	cout << par - 1 << '\n';
	for (pair<int, int> i : V)	cout << i.first << ' ' << i.second << '\n';
}