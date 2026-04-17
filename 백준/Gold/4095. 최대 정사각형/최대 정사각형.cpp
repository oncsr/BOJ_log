#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	for (cin >> N >> M; N || M; cin >> N >> M) {
		vector<vector<int>> arr(N + 1, vector<int>(M + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> arr[i][j];
				arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!arr[i][j])	continue;
				ans = max(ans, 1);
				for (int k = ans - 1; i + k <= N && j + k <= M; k++) {
					if (arr[i + k][j + k] - arr[i - 1][j + k] - arr[i + k][j - 1] + arr[i - 1][j - 1] == (k + 1) * (k + 1))
						ans = max(ans, k + 1);
					else	break;
				}

			}
		}
		cout << ans << '\n';
	}

}