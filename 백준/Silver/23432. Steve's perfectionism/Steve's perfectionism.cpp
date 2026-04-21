#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, t;
	cin >> n >> t;
	cout << t << ' ';
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (a <= t) {
			t = (t / a + 1) * a;
		}
		else	t = a;
		cout << t << ' ';
	}

}