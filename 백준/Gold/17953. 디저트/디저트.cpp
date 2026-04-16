#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, A[100001][10]{}, dp[100001][10]{};

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) for (int j = 1; j <= N; j++) cin >> A[j][i];

	for (int i = 0; i < M; i++) dp[1][i] = A[1][i];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				if (j == k) dp[i][j] = max(dp[i][j], dp[i - 1][k] + A[i][j] / 2);
				else dp[i][j] = max(dp[i][j], dp[i - 1][k] + A[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) ans = max(ans, dp[N][i]);
	cout << ans;

}