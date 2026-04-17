#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, mn = 2e9 + 3;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (auto& [i, j] : arr)	cin >> i >> j;
	sort(arr.begin(), arr.end());

	for (int i = 1; i < N; i++) {
		auto [px, ph] = arr[i - 1];
		auto [x, h] = arr[i];
		if (px + ph / 2 < x - h / 2)	continue;
		else {
			int g = min(h, ph);
			if (px + g / 2 >= x - g / 2)	mn = min(mn, (x - px - 1) / 2);
			else	mn = min(mn, x - px - g / 2 - 1);
		}
	}
	if (mn == 2e9 + 3)	cout << "forever";
	else	cout << mn;
	

}