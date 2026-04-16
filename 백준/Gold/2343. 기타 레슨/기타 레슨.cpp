#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, arr[100000]{}, s = 1, e = 1e9, m;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i], s = max(s, arr[i]);

	m = (s + e) >> 1;
	while (s < e) {
		int c = 0, t = 1;
		for (int i = 0; i < N; i++) {
			if (c + arr[i] > m)	t++, c = arr[i];
			else	c += arr[i];
		}
		if (t > M)	s = m + 1;
		else	e = m;
		m = (s + e) >> 1;
	}
	cout << m;

}