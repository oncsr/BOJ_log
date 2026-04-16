#include <iostream>
#include <functional>
#include <numeric>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, N, M, a, b, r[1001]{};
	function<int(int)> f = [&](int x) -> int { return x == r[x] ? x : r[x] = f(r[x]); };
	for (cin >> T; T--;) {
		cin >> N >> M;
		int cnt = 0;
		for (iota(r, r + N + 1, 0); M--;) {
			cin >> a >> b;
			int x = f(a), y = f(b);
			if (x == y) cnt += N;
			else r[x] = y, cnt++;
		}
		cout << (cnt == N - 1 ? "tree\n" : "graph\n");
	}

}