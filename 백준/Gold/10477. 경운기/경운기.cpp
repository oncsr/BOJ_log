#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int A, B;
		cin >> A >> B;

		long long ans = 1;
		for (int i = 1; (1 << i) - 1 <= A + B; i++) {
			ans += min(A + 1, (1 << i)) - max(0, (1 << i) - (B + 1));
		}
		cout << ans << '\n';
	}
	
}