#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, S, arr[100001]{}, left[100001]{}, right[100001]{};
	cin >> n >> S;
	for (int i = 1; i <= n; i++)	cin >> arr[i], left[i] = arr[i], right[i] = arr[i];
	left[1] = arr[1], right[n] = arr[n];
	for (int i = 2; i <= n; i++)	left[i] += left[i - 1];
	for (int i = n - 1; i >= 1; i--)	right[i] += right[i + 1];
	reverse(right + 1, right + n + 1);
	int id = 1, ans[100001]{};
	while (id < n) {
		if (arr[id] > S || arr[id + 1] > S) {
			id++;
			continue;
		}
		int L = upper_bound(right, right + n + 1, S + right[n - id]) - (right + n - id + 2);
		int R = upper_bound(left, left + n + 1, S + left[id]) - (left + id + 2);
		int mn = max(0, min(L, R));
		ans[id - mn] = max(ans[id - mn], mn * 2 + 2);
		id++;
	}
	int prev = ans[1];
	cout << prev << '\n';
	prev -= 2;
	for (int i = 2; i <= n; i++) {
		if (ans[i] > prev)	prev = ans[i];
		cout << prev << '\n';
		prev -= 2;
	}
}