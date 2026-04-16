#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	priority_queue<pair<double, char>> Q;
	Q.emplace((double)b * 10 / (a * 10 >= 5000 ? a * 10 - 500 : a * 10), 'S');
	Q.emplace((double)d * 10 / (c * 10 >= 5000 ? c * 10 - 500 : c * 10), 'N');
	Q.emplace((double)f * 10 / (e * 10 >= 5000 ? e * 10 - 500 : e * 10), 'U');
	cout << Q.top().second;

}