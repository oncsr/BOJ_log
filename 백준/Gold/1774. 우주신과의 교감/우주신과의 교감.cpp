#include <bits/stdc++.h>
using namespace std;

int root[1001]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	double X[1001]{}, Y[1001]{};
	vector<pair<double, pair<int, int>>> E;
	for (int i = 1; i <= N; i++) {
		root[i] = i;
		cin >> X[i] >> Y[i];
		for (int j = 1; j < i; j++) {
			double D = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
			E.push_back({ D, {i,j} });
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int x = find(a), y = find(b);
		root[x] = y;
	}
	sort(E.begin(), E.end());
	double ans = 0;
	for (auto e : E) {
		int a = e.second.first, b = e.second.second;
		double cost = e.first;
		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		ans += cost;
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << ans;
	cout.unsetf(ios::fixed);
}