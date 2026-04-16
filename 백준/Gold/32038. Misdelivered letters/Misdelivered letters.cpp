#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T;
	cin >> N >> T;
	random_device rd;
	mt19937 mte(rd());
	uniform_int_distribution<int> U(1, N);

	while (T--) {
		vector<int> vis(N + 1);

		while (1) {
			int x, y;
			char r;
			do x = U(mte); while (vis[x]);
			cout << "Q " << x << endl;
			cin >> y;
			if (x == y) {
				cout << "A " << x << endl;
				cin >> r;
				if (r == 'W')	return 0;
				break;
			}
			vis[x]++, vis[y]++;
		}

	}

}