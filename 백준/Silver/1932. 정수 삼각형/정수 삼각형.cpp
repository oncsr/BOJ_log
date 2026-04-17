#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int arr[501][501]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= i; j++)	cin >> arr[i][j];

	int dp[502][502]{};
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
		}
	}

	cout << *max_element(dp[N] + 1, dp[N] + N + 1);

}