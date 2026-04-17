#include <bits/stdc++.h>
using namespace std;

int ans = 100, N, M;

int L[11]{};

void solve(int pos, int sel, int state) {
	if (pos == M + 1) {
		if (state == (1 << (N + 1)) - 2)	ans = min(ans, sel);
		return;
	}
	solve(pos + 1, sel, state);
	solve(pos + 1, sel + 1, state | L[pos]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a;
		for (cin >> a; a--;) {
			int b;
			cin >> b;
			L[i] |= (1 << b);
		}
	}
	solve(1, 0, 0);
	cout << (ans == 100 ? -1 : ans);

}