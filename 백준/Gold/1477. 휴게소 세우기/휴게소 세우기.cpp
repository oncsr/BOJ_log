#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, L;
	cin >> N >> M >> L;
	vector<int> V = { 0,L };
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		V.push_back(a);
	}
	sort(V.begin(), V.end());
	int s = 1, e = L, m = (s + e) >> 1;
	while (s < e) {
		int cnt = 0;
		for (int i = 1; i <= N + 1; i++)
			cnt += (V[i] - V[i - 1] - 1) / m;
		if (cnt > M)	s = m + 1;
		else	e = m;
		m = (s + e) >> 1;
	}
	cout << m;
}