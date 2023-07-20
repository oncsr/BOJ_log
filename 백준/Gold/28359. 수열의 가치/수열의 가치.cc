#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, ans = 0;
	cin >> N;
	int arr[1001]{};
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		ans += a;
		arr[a]++;
	}
	int mx = 0, num;
	for (int i = 1; i <= 1000; i++) {
		if (arr[i] * i > mx)	mx = arr[i] * i, num = i;
	}
	cout << ans + mx << '\n';
	for (int i = 1; i <= N; i++) {
		if (num == i)	break;
		for (int j = arr[i]; j > 0; j--)	cout << i << ' ';
		arr[i] = 0;
	}
	for (int i = 1000; i >= 1; i--) {
		for (int j = arr[i]; j > 0; j--)	cout << i << ' ';
		arr[i] = 0;
	}
}