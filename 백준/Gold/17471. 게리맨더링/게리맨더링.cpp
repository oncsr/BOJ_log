#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int r[10]{}, s[10]{}, N;

int f(int x) { return x == r[x] ? x : r[x] = f(r[x]); }
int ans = 1e9;
vector<pair<int, int>> E;

void sol(int pos, int mask, int ca, int cb, int sa, int sb) {
	if (pos == N) {
		iota(r, r + N, 0);
		int c[2]{};
		for (auto[p, q] : E) {
			int x = f(p), y = f(q);
			if (x == y) continue;
			int mx = (mask & (1 << x)) ? 1 : 0, my = (mask & (1 << y)) ? 1 : 0;
			if (mx != my) continue;
			r[x] = y;
			c[mx]++;
		}
		if (c[0] == ca - 1 && c[1] == cb - 1) ans = min(ans, abs(sa - sb));
		return;
	}
	sol(pos + 1, mask, ca + 1, cb, sa + s[pos], sb);
	sol(pos + 1, mask | (1 << pos), ca, cb + 1, sa, sb + s[pos]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	for (int i = 0, j, a; i < N; i++) {
		for (cin >> j; j--; E.emplace_back(i, a-1)) cin >> a;
	}
	sol(0, 0, 0, 0, 0, 0);
	cout << (ans == 1e9 ? -1 : ans);

}