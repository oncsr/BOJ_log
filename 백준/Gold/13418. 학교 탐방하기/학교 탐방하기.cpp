#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	
	int r[1001]{};
	function<int(int)> f = [&](int x) -> int {return x == r[x] ? x : r[x] = f(r[x]); };

	iota(r, r + N + 1, 0);
	vector<tuple<int, int, int>> E;
	for (int i = 0, a, b, c; i++ <= M; E.emplace_back(c,a,b)) cin >> a >> b >> c;

	auto g = [&](int tar) -> int {
		iota(r, r + N + 1, 0);
		if (tar) sort(E.begin(), E.end(), greater<>());
		else sort(E.begin(), E.end(), less<>());

		int res = 0;
		for (auto [c, a, b] : E) {
			int x = f(a), y = f(b);
			if (x == y) continue;
			r[x] = y;
			res += c == tar;
		}
		return res;
	};

	int p = g(0), q = N - g(1);
	cout << abs(p*p - q * q);

}