#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, N, M;
	cin >> T >> N;
	vector<int> arr(N);
	vector<int> A, B;
	for (int& i : arr)	cin >> i;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			A.push_back(sum);
		}
	}

	cin >> M;
	arr.resize(M);
	for (int& i : arr)	cin >> i;
	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += arr[j];
			B.push_back(sum);
		}
	}

	sort(B.begin(), B.end());
	long long ans = 0;
	for (int i : A) {
		ans += upper_bound(B.begin(), B.end(), T - i) - lower_bound(B.begin(), B.end(), T - i);
	}
	cout << ans;

}