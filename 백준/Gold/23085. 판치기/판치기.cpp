#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	int f = 0, b = 0;
	for (char i : s)	f += i == 'H', b += i == 'T';

	int v[3001][3001]{};
	v[f][b]++;
	queue<tuple<int, int, int>> Q;
	Q.emplace(f, b, 0);
	while (!Q.empty()) {
		auto [a, b, t] = Q.front();	Q.pop();
		if (b == n)	return cout << t, 0;
		for (int i = 0; i <= k; i++) {
			int A = a + k - 2 * i, B = b - k + 2 * i;
			if (i <= a && k - i <= b && A <= n && B <= n && !v[A][B]) {
				v[A][B]++;
				Q.emplace(A, B, t + 1);
			}
		}
	}
	cout << -1;

}