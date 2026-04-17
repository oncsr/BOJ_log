#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, ans = 0;
	cin >> N >> M;

	auto sol = [&](int A, int B) -> int {
		while (A) {
			int x = A & 1, y = B & 1;
			A >>= 1, B >>= 1;
			if (x < y)	return 0;
		}
		return 1;
	};
	auto sol2 = [&](int s, int e) -> void {
		while (e >= 0) {
			int x;
			cin >> x;
			ans ^= (x & sol(s, e));
			s--, e--;
		}
	};
	sol2(N + M - 2, N - 1);
	sol2(N + M - 2, M - 1);
	cout << ans;
}