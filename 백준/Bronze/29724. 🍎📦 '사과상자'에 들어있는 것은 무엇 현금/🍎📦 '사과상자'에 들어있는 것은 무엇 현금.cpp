#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int G = 0, S = 0, N;
	for (cin >> N; N--;) {
		char T;
		int W, H, L;
		cin >> T >> W >> H >> L;
		if (T == 'B') {
			G += 6000;
			continue;
		}
		int cnt = (W / 12) * (H / 12) * (L / 12);
		G += 1000 + cnt * 500;
		S += cnt * 4000;
	}
	cout << G << '\n' << S;

}