#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ld arr[10001]{};
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	ld dp[10001]{};
	ld mx = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		mx = max(mx, dp[i]);
	}
	cout.precision(3);
	cout << fixed << mx;

}