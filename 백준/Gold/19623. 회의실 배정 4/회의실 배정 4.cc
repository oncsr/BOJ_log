#include <bits/stdc++.h>
using namespace std;

int D[524289]{};

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		D[n] = max(D[n], v);
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	D[n] = max(D[n * 2], D[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return D[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, cnt = 0;
	cin >> N;
	vector<tuple<int, int, int>> A(N);
	map<int, int> M;
	vector<int> V;
	for (auto& [a, b, c] : A)	cin >> a >> b >> c, V.push_back(a), V.push_back(b);

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i : V)	M[i] = ++cnt;

	for (auto& [a, b, c] : A)	a = M[a], b = M[b];

	sort(A.begin(), A.end(), [](auto a, auto b) -> bool {
		auto [sa, ea, _a] = a;
		auto [sb, eb, _b] = b;
		if (ea == eb)	return sa < sb;
		return ea < eb;
	});

	
	for (auto [a, b, c] : A) {
		upt(1, 2 * N, b, find(1, 2 * N, 1, a, 1) + c, 1);
	}
	cout << D[1];

}