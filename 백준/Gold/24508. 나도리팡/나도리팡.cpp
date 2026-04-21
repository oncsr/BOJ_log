#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, K, T;
	cin >> N >> K >> T;
	int arr[100000]{};
	ll S = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		S += arr[i];
	}
	if (S % K) {
		cout << "NO";
		return 0;
	}
	sort(arr, arr + N, greater<int>());
	ll ans = 0;
	int s = 0, e = N - 1;
	while (s < e) {
		while (0 < arr[s] && arr[s] < K) {
			int G = min(K - arr[s], arr[e]);
			arr[s] += G;
			arr[e] -= G;
			ans += G;
			if (!arr[e])	e--;
		}
		arr[s++] = 0;
	}
	if (ans > T)	cout << "NO";
	else	cout << "YES";

}