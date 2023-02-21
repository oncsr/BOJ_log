#include <iostream>
using namespace std;

struct F {
	int f[5]{};
};
int N, Q;

F seg[262145]{};
F arr[100001]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	for (int i = 0; i < 5; i++)
		seg[n].f[i] = seg[n * 2].f[seg[n * 2 + 1].f[i] - 1];
}

F find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 1,2,3,4,5 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	F left = find(s, m, l, r, n * 2);
	F right = find(m + 1, e, l, r, n * 2 + 1);
	F tot;
	for (int i = 0; i < 5; i++)
		tot.f[i] = left.f[right.f[i] - 1];
	return tot;
}

void change(int s, int e, int i, F v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	change(s, m, i, v, n * 2);
	else	change(m + 1, e, i, v, n * 2 + 1);
	for (int i = 0; i < 5; i++)
		seg[n].f[i] = seg[n * 2].f[seg[n * 2 + 1].f[i] - 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i].f[j];
	init(1, N, 1);
	for (cin >> Q; Q--;) {
		int u, a, b, q, w, e, r, t;
		cin >> u >> a >> b >> q >> w >> e >> r >> t;
		F right = find(1, N, u + 1, b, 1);
		F ans = { q,w,e,r,t };
		F left = find(1, N, a, u - 1, 1);
		F mid1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (ans.f[i] == left.f[j]) {
					mid1.f[i] = j + 1;
					break;
				}
			}
		}
		F fu;
		for (int i = 0; i < 5; i++)	fu.f[right.f[i] - 1] = mid1.f[i];
		change(1, N, u, fu, 1);
		for (int i = 0; i < 5; i++)	cout << fu.f[i] << ' ';
		cout << '\n';
	}
}