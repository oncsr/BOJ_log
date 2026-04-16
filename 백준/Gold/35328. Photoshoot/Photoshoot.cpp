#include <bits/stdc++.h>
using namespace std;

int N, K, Q;
int arr[501][501]{}, val[501][501]{};
int mx = 0;

void upt(int x, int y, int v) {
	for (int i = max(1, x - K + 1); i <= x; i++) {
		for (int j = max(1, y - K + 1); j <= y; j++) {
			arr[i][j] += v - val[x][y];
			mx = max(mx, arr[i][j]);
		}
	}
	val[x][y] = v;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K >> Q;
	for (int x, y, v; Q--;) {
		cin >> x >> y >> v;
		upt(x, y, v);
		cout << mx << '\n';
	}

}