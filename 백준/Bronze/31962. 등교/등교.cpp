#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, X, ans = -1;
	for (cin >> N >> X; N--;) {
		int s, t;
		cin >> s >> t;
		if (s + t <= X)	ans = max(ans, s);
	}
	cout << ans;

}