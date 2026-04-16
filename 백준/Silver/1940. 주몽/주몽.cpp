#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int arr[15000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	int s = 0, e = N - 1, ans = 0;
	while (s < e) {
		if (arr[s] + arr[e] == M) {
			ans++;
			e--;
		}
		else if (arr[s] + arr[e] < M) {
			s++;
		}
		else {
			e--;
		}
	}
	cout << ans;


}