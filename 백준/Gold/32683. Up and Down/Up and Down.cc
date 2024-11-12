#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		vector<int> A(N), V, L(N), R(N);
		for (int& i : A)	cin >> i;

		for (int i = 0; i < N; i++) {
			int p = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
			if (p == V.size())	V.push_back(A[i]);
			else	V[p] = A[i];
			L[i] = p + 1;
		}
		V = vector<int>();
		for (int i = N - 1; i >= 0; i--) {
			int p = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
			if (p == V.size())	V.push_back(A[i]);
			else	V[p] = A[i];
			R[i] = p + 1;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (L[i] == 1 || R[i] == 1)	continue;
			ans = max(ans, L[i] + R[i] - 1);
		}
		cout << ans << '\n';

	}

}