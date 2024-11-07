#include <bits/stdc++.h>
#include <array>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, v, c[5]{};
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> c[i];
	cin >> v;
	
	map<array<int, 5>, int> D;
	priority_queue<pair<int, array<int, 5>>, vector<pair<int, array<int, 5>>>, greater<>> Q;
	array<int, 5> st{ c[0],0,0,0,0 };
	D[st] = 0;
	Q.emplace(0, st);
	while (!Q.empty()) {
		auto [d, a] = Q.top();	Q.pop();
		if (d > D[a])	continue;
		if (a[0] == v)	return cout << d, 0;
		for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++) {
			if (i == j)	continue;
			int p = min(a[i], c[j] - a[j]);
			a[i] -= p, a[j] += p;
			if (D.find(a) == D.end() || D[a] > d + p) {
				D[a] = d + p;
				Q.emplace(d + p, a);
			}
			a[i] += p, a[j] -= p;
		}
	}
	cout << "impossible";

}