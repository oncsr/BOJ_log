#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	cin.tie(0)->sync_with_stdio(0);

	//////////////////////////////////////////////////////

	int map[501][501]{};
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = N - 1; j > 0; j--) {
			map[i][j] += map[i][j + 1];
		}
	}
	/*
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	

	int d[501][501]{};
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			if (i == 1)	d[i][j] = map[i][j];
			else	d[i][j] = min(d[i - 1][j], map[i][j]);

		}
	}
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	for (; Q--;) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int ans = min(map[a][b], d[a - c][b]);
		for (int i = b + 1; i <= N; i++)	ans = min(ans, map[a][b] - map[a][i] + d[a - c][i]);
		cout << ans << '\n';
	}

}

/*
* [shake! 2022]
*
* < 사용한 자료구조, 알고리즘 >
* dp, prefix sum
*
* < 참고한 자료 >
* x
*
* < 출처 >
* x
*
*/