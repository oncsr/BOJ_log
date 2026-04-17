#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, q;
	cin >> n >> m >> q;
	int cnt = n * m;
	int arr[1001][1001]{};

	for (; q--;) {
		int o, a, b, c, d;
		cin >> o;
		if (o == 3) { cout << cnt << '\n'; continue; }
		cin >> a >> b;
		if (o == 2) { cout << arr[a][b] << '\n'; continue; }
		cin >> c >> d;
		while (1 <= c && c <= n && 1 <= d && d <= m) {
			if (arr[c][d])	break;
			arr[c][d] = 1;
			cnt--;
			c += a, d += b;
		}
	}

}