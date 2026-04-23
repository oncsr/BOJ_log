#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define A(p,q,s)	p.begin(), p.end(), q.begin(), q.end(), s.begin()
vector<vector<int> > seg(262145);
int N, Q, r[100001]{}, a, b, c;

void I(int s, int e, int n) {
	if (s == e) {
		seg[n].push_back(r[s]);
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	seg[n].resize(seg[n * 2].size() + seg[n * 2 + 1].size());
	merge(A(seg[n * 2], seg[n * 2 + 1], seg[n]));
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n].end() - upper_bound(seg[n].begin(), seg[n].end(), c);
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> r[i];
	I(1, N, 1);
	for (cin >> Q; Q--;) {
		cin >> a >> b >> c;
		cout << find(1, N, a, b, 1) << '\n';
	}
}