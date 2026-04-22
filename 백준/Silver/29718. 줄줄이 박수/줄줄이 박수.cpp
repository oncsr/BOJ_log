#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, arr[2001]{};
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			arr[j] += a;
		}
	}
	int A;
	cin >> A;
	for (int i = 1; i <= m; i++)	arr[i] += arr[i - 1];
	int mx = 0;
	for (int i = A; i <= m; i++)	mx = max(mx, arr[i] - arr[i - A]);
	cout << mx;
}