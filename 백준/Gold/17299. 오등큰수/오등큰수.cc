#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[1000000]{}, N, cnt[1000001]{}, arr2[1000000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i], cnt[arr[i]]++;
	for (int i = 0; i < N; i++)	arr2[i] = cnt[arr[i]];

	vector<int> ans(1000001, -1);
	stack<ii> S;

	for (int i = 0; i < N; i++) {
		if (S.empty()) {
			S.push({ arr2[i], i });
			continue;
		}
		while (!S.empty() && arr2[i] > S.top().first) {
			ans[S.top().second] = arr[i];
			S.pop();
		}
		S.push({ arr2[i], i });
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
}