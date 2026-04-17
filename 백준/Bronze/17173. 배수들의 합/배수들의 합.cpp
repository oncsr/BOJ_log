#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, ans = 0;
	cin >> N >> M;
	vector<int> arr(M);
	for (int& i : arr)	cin >> i;
	for (int i = 1; i <= N; i++) {
		bool f = 0;
		for (int j : arr) {
			if (i % j == 0) {
				f = 1;
				ans += i;
				break;
			}
		}
		if (f)	continue;
	}
	cout << ans;
}