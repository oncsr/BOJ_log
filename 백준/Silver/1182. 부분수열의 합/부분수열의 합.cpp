#include <bits/stdc++.h>
using namespace std;

int arr[20]{}, n, S, ans = 0;

void solve(int pos, int sum, int sel) {
	if (pos == n) {
		if (sel && sum == S)	ans++;
		return;
	}
	solve(pos + 1, sum, sel);
	solve(pos + 1, sum + arr[pos], sel + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> S;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	solve(0, 0, 0);
	cout << ans;
}