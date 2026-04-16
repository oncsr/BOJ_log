#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> max_left, max_right;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	for (int& i : arr) cin >> i;
	cin >> M;

	max_left.resize(N);
	max_right.resize(N);

	int sum = 0;
	for (int i = 0; i < M; i++) sum += arr[i];

	max_left[M - 1] = sum;
	for (int i = M; i < N; i++) {
		sum += arr[i] - arr[i - M];
		max_left[i] = max(max_left[i - 1], sum);
	}

	sum = 0;
	for (int i = N - 1; i > N - 1 - M; i--) sum += arr[i];

	max_right[N - M] = sum;
	for (int i = N - M - 1; i >= 0; i--) {
		sum += arr[i] - arr[i + M];
		max_right[i] = max(max_right[i + 1], sum);
	}

	sum = 0;
	for (int i = M; i < 2 * M; i++) sum += arr[i];

	int ans = max_left[M - 1] + sum + max_right[2 * M];
	for (int i = 2 * M; i < N - M; i++) {
		sum += arr[i] - arr[i - M];
		ans = max(ans, max_left[i - M] + sum + max_right[i + 1]);
	}
	cout << ans;
	
}