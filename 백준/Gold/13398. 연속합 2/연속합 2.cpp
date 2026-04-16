#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int N;
	cin >> N;
	int arr[100002]{}, left[100002]{}, right[100002]{};
	int ans = -2e9;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		left[i] = max(left[i - 1] + arr[i], arr[i]);
		ans = max(ans, left[i]);
	}
	for (int i = N; i >= 1; i--) {
		right[i] = max(right[i + 1] + arr[i], arr[i]);
		if (i - 1 < 1 && i + 1 > N)	continue;
		ans = max(ans, left[i - 1] + right[i + 1]);
	}

	cout << ans;

}