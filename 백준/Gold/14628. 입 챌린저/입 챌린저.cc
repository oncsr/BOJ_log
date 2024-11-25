#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, K, inf = 1234567890;
	cin >> N >> M >> K;

	vector<int> D(101, inf);
	D[M] = 0;

	for (int i = 0, x, y; i < N; i++) {
		cin >> x >> y;
		vector<int> ND(101, inf);
		for (int c = 1; c * y <= M; c++) {
			int mana = c * x + c * (c - 1) / 2 * K;
			for (int j = M; j >= c * y; j--) {
				ND[j - c * y] = min(ND[j - c * y], D[j] + mana);
			}
		}
		for (int j = 0; j <= M; j++)	ND[j] = min(ND[j], D[j]);
		D = ND;
	}
	cout << D[0];

}