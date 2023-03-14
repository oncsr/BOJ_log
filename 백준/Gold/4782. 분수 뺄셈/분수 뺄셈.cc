#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

bool cmp(pair<double, pair<ll, ll> > a, pair<double, pair<ll, ll> > b) {
	if (a.first == b.first)	return a.second.first < b.second.first;
	return a.first < b.first;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll b, n;
	for (cin >> b >> n; b != 0 && n != 0; cin >> b >> n) {
		vector<pair<double, pair<ll, ll> > > V;
		for (ll a = 0; a < b; a++) {
			double g = sqrt(b * b - a * b);
			ll gg = g;
			if (g == gg) {
				double f = (double)gg * n / (double)b;
				ll ff = f;
				if (f == ff) {
					ll m = n + ff;
					V.push_back({ (double)a / ((double)n + f),{a,m} });
					if (m - 2 * ff > 0)	V.push_back({ (double)a / ((double)n - f),{a,m - 2 * ff} });
				}
			}
		}
		sort(V.begin(), V.end(), cmp);
		for (const pair<double, pair<ll, ll> > now : V) {
			cout << now.second.first << '/' << now.second.second << ' ';
		}
		cout << '\n';
	}
}