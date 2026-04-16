#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> X(N), T(N);
	for (int& i : X)	cin >> i;
	for (int& i : T)	cin >> i;

	int ans = max(X[N - 1], T[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		int dist = X[i + 1] - X[i];
		ans = max(ans + dist, T[i]);
	}
	cout << ans + X[0];

}