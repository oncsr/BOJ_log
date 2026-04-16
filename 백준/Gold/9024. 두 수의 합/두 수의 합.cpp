#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		cin >> N >> K;
		arr = vector<int>(N);
		for (int& i : arr) cin >> i;
		sort(arr.begin(), arr.end());
		
		int mn = 2e9 + 7, ans = 0;
		for (int i = 0; i < N; i++) {
			int idx = lower_bound(arr.begin(), arr.end(), K - arr[i]) - arr.begin();
			if (idx == i) {
				if (idx + 1 < N) {
					int val = abs(K - arr[i] - arr[idx + 1]);
					if (val < mn) {
						mn = val;
						ans = 1;
					}
					else if (val == mn) ans++;
				}
				if (idx - 1 >= 0) {
					int val = abs(K - arr[i] - arr[idx - 1]);
					if (val < mn) {
						mn = val;
						ans = 1;
					}
					else if (val == mn) ans++;
				}
			}
			else {
				if (idx < N) {
					int val = abs(K - arr[i] - arr[idx]);
					if (val < mn) {
						mn = val;
						ans = 1;
					}
					else if (val == mn) ans++;
				}
				if (idx - 1 == i) idx--;
				if (idx - 1 >= 0) {
					int val = abs(K - arr[i] - arr[idx - 1]);
					if (val < mn) {
						mn = val;
						ans = 1;
					}
					else if (val == mn) ans++;
				}
			}
		}
		cout << ans / 2 << '\n';
	}

}