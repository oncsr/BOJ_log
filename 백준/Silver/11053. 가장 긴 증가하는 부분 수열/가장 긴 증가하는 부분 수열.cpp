#include <bits/stdc++.h>
using namespace std;

int n;
int memo[1001]{};
int arr[1001]{};

int dp(int n) {
	if (n == 1)	return 1;
	int mx = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[n]) {
			if (!memo[i])	memo[i] = dp(i);
			mx = max(mx, memo[i] + 1);
		}
	}
	memo[n] = mx;
	return mx;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];

	int mx = 0;
	for (int i = 1; i <= n; i++)	mx = max(mx, dp(i));
	cout << mx;

}