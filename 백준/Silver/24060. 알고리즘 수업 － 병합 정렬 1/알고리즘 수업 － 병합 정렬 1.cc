#include <bits/stdc++.h>
using namespace std;

int N, arr[500000]{}, c = 0, ans = -1, K;

void merge(int p, int q, int r) {
	sort(arr + p, arr + r + 1);
	if (K <= r - p + 1 && K >= 0) {
		ans = arr[p + K - 1];
		K = -1;
		return;
	}
	K -= (r - p + 1);
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	merge_sort(0, N - 1);
	if (ans < 0)	cout << -1;
	else	cout << ans;
}