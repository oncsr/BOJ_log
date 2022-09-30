#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first < b.first;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k, m, a, b, p=0, q=0, r;
	cin >> n >> k;
	vector<pair<int, int> > V;
	int warn[1001]{};
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		V.push_back({ min(a,b),max(a,b) });
	}
	sort(V.begin(), V.end(), compare);
	cin >> m;
	while (m--) {
		cin >> a >> b;
		int cur = min(a,b);
		int last = max(a, b);
		bool bus = false;
		for (int i = 0; i < k; i++) {
			if (V[i].second <= cur)	continue;
			if (V[i].first >= last)	break;
			bus = true;
			if (!warn[i]) {
				warn[i]++;
				q++;
			}
		}
		if (bus)p++;
	}
	r = V[0].first;
	for (int i = 1; i < k; i++)
		r = max(r, V[i].first - V[i - 1].second + 1);
	r = max(r, n - V[k - 1].second + 1);
	cout << p << '\n' << q << '\n' << r;
}