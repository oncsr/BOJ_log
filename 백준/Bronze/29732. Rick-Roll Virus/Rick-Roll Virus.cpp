#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m, k, v = 0, b = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		char a;
		cin >> a;
		if (a == 'R') {
			v += max(0, min(n, i + k) - max(b, max(i - k - 1, 0)));
			b = min(n, i + k);
		}
	}
	cout << (v > m ? "No" : "Yes");
}