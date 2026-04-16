#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K, ans = -1e9;
	cin >> N >> K;
	int arr[10][10]{};
	if (K == 1)	return cout << 0, 0;
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> arr[i][j];

	for (int i = 1; i < (1 << N); i++) {
		vector<int> T;
		for (int j = 0; j < N; j++) {
			if ((1 << j) & i)	T.push_back(j);
		}
		if (T.size() != K)	continue;

		int res = 0;
		for (int a = 0; a < T.size(); a++) {
			for (int b = a + 1; b < T.size(); b++) {
				res += arr[T[a]][T[b]];
			}
		}
		ans = max(ans, res);

	}
	cout << ans;

}