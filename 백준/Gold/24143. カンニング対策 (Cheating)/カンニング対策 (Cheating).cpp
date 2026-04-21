#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<int> x(M), y(M);
	for (int i = 0; i < M; i++)	cin >> x[i] >> y[i];
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int s = 0, e = 1e9, m = (s + e) >> 1;
	while (s < e) {
		int cnt = 1, st = x[0];
		for (int i : x) {
			if (i > st + m) {
				cnt++;
				st = i;
			}
		}
		cnt++, st = y[0];
		for (int i : y) {
			if (i > st + m) {
				cnt++;
				st = i;
			}
		}
		if (cnt <= N)	e = m;
		else	s = m + 1;
		m = (s + e) >> 1;
	}
	cout << m;

}