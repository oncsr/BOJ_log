#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, C, mx = 0, mn = 1000000001;
	int arr[200000]{};
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
	}
	sort(arr, arr + N);
	int s = 0, e = mx - mn, m = (s + e + 1) / 2;
	while (s <= e) {
		int cnt = 0, pos = 0;
		for (int i = 0; i < N; i++) {
			if (!cnt)	cnt++, pos = arr[i];
			else {
				if (arr[i] - pos >= m)	cnt++, pos = arr[i];

			}
		}
		if (cnt >= C) {
			if (s == m)	break;
			s = m;
		}
		else {
			if (e == m - 1)	break;
			e = m - 1;
		}
		m = (s + e + 1) / 2;
	}
	cout << m;
}