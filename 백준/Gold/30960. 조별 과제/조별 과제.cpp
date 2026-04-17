#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, arr[500000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	ll cnt = arr[2] - arr[0];
	for (int i = 3; i < N; i += 2)	cnt += arr[i + 1] - arr[i];
	ll mn = cnt;
	for (int i = 2; i < N - 1; i += 2) {
		cnt -= arr[i] - arr[i - 2];
		cnt += arr[i + 2] - arr[i];
		cnt += arr[i - 1] - arr[i - 2];
		cnt -= arr[i + 2] - arr[i + 1];
		mn = min(mn, cnt);
	}
	cout << mn;

}