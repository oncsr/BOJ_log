#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, c;
	cin >> N >> c >> b;
	int ans = min(b, c);
	for (int i = 3; i <= N; i++) {
		cin >> a;
		priority_queue<int> Q;
		Q.emplace(a);	Q.emplace(b);	Q.emplace(c);
		Q.pop();
		ans = max(ans, Q.top());
		c = b;
		b = a;
	}
	cout << ans;

}