#include <iostream>
#include <vector>
using namespace std;

/*
* 2022.11.16
* [used algorithm]
* =>
* [point]
* =>
*/
int T, N, M, a;
vector<int> seg(524289);
vector<int> order(100001);
void I(int s, int e, int n) {
	if (s == e) {
		if (s <= N)	seg[n] = 1;
		else	seg[n] = 0;
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void query(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] += v;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, v, n * 2);
	else	query(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> T; T--;) {
		cin >> N >> M;
		seg = vector<int>(524289);
		order = vector<int>(N + 1);
		I(1, N + M, 1);
		int id = N + 1;
		for (int i = 1; i <= N; i++)	order[N - i + 1] = i;
		for (int i = 0; i < M; i++) {
			cin >> a;
			query(1, N + M, order[a], -1, 1);
			cout << find(1, N + M, order[a] + 1, id - 1, 1) << ' ';
			query(1, N + M, id, 1, 1);
			order[a] = id++;
		}
		cout << '\n';
	}
}