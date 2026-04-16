#include <iostream>
#include <algorithm>
using namespace std;

int n, a[2002]{}, dp[2001][2001]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if(j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[j] * i);
			if(j < i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[n - (i - j) + 1] * i);
		}
	}
	cout << *max_element(dp[n], dp[n] + n + 1);

}