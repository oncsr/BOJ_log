#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, arr[500001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	vector<ll> A(500001);
	vector<ll> B(500002);
	A[1] = arr[1], B[N] = arr[N];
	for (int i = 2; i <= N; i++) {
		A[i] = max(A[i - 1] + arr[i], arr[i]);
	}

	ll s = arr[N];
	for (int i = N - 1; i >= 1; i--) {
		B[i] = max(B[i + 1] + arr[i], arr[i]);
		s += arr[i];
	}

	for (int i = 1; i <= N; i++)	A[i] = max(A[i - 1], A[i]);
	for (int i = N; i >= 1; i--)	B[i] = max(B[i + 1], B[i]);

	ll ans = -1e18;
	for (int i = 1; i < N; i++)	ans = max(ans, A[i] + B[i + 1]);
	cout << ans + s;

}