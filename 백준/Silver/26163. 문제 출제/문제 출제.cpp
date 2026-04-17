#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int ans = 0;
	int b[5]{};
	for (int i = 0; i < 5; i++)	cin >> b[i];

	for (int q = 0; q <= 10; q++) {
		for (int w = 0; w <= 10; w++) {
			for (int e = 0; e <= 10; e++) {
				for (int r = 0; r <= 10; r++) {
					for (int t = 0; t <= 10; t++) {
						if (q + 2 * w + 3 * e + 4 * r + 5 * t > 10)	continue;
						if (q + w + e + r + t > 3)	continue;
						ans = max(ans, b[0] * q + b[1] * w + b[2] * e + b[3] * r + b[4] * t);
					}
				}
			}
		}
	}

	for (int q = 0; q <= 15; q++) {
		for (int w = 0; w <= 15; w++) {
			for (int e = 0; e <= 15; e++) {
				for (int r = 0; r <= 15; r++) {
					for (int t = 0; t <= 15; t++) {
						if (q + 2 * w + 3 * e + 4 * r + 5 * t > 15)	continue;
						if (q + w + e + r + t <= 3)	continue;
						ans = max(ans, b[0] * q + b[1] * w + b[2] * e + b[3] * r + b[4] * t);
					}
				}
			}
		}
	}

	cout << ans;

}