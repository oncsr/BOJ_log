#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double f;
	cin >> n >> f;
	vector<pair<double, double> > V;
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		V.push_back({ (f - a) / b, i });
	}
	sort(V.begin(), V.end());
	cout << V[0].second;
}