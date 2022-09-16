#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y, ans = 0, temp = 0;
	cin >> n;
	vector<pair<int, int> > V;
	while (n--) {
		cin >> x >> y;
		V.push_back({ x,y });
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		x = V[i].first, y = V[i].second;
		if (y < temp)	continue;
		ans += (y - x) * (y - x);
		if (x < temp)	ans -= (temp - x) * (temp - x);
		temp = y;
	}
	cout << ans << '\n';
}