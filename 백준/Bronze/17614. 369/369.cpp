#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		string now = to_string(i);
		for (auto ch : now) {
			if (ch == '3' || ch == '6' || ch == '9') {
				ans++;
			}
		}
	}

	cout << ans;

}