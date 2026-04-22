#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int arr[1000000]{}, cnt[1000001]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	int ans[1000000]{};
	stack<pair<int, int>> S;
	for (int i = 0; i < N; i++) {
		if (S.empty()) {
			S.push({ cnt[arr[i]], i });
			continue;
		}
		while (!S.empty() && cnt[arr[i]] > S.top().first) {
			ans[S.top().second] = arr[i];
			S.pop();
		}
		S.push({ cnt[arr[i]], i });
	}
	while (!S.empty()) {
		ans[S.top().second] = -1;
		S.pop();
	}
	for (int i = 0; i < N; i++)	cout << ans[i] << ' ';
}