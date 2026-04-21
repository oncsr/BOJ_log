#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		int arr[200]{};
		for (int i = 0; i < 2 * N; i++)	cin >> arr[i];
		int vis[200]{};
		vector<int> ans;
		for (int i = 2 * N - 1; i >= 0; i--) {
			if (vis[i])	continue;
			ans.push_back(arr[i] / 4 * 3);
			vis[i]++;
			for (int j = 0; j < i; j++) {
				if (vis[j])	continue;
				if (arr[j] == arr[i] / 4 * 3) { vis[j]++; break; }
			}
		}
		cout << "Case #" << t << ": ";
		for (int i = ans.size() - 1; i >= 0; i--)	cout << ans[i] << ' ';
		cout << '\n';
	}

}