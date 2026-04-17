#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[200000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i];
	ll ans = 1, cnt = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] > arr[i - 1])	cnt++;
		else	cnt = 1;
		ans += cnt;
	}
	cout << ans;

}