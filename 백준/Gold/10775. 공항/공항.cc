#include <iostream>
using namespace std;

int seg[262145]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = s;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2); init(m + 1, e, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

void upt(int s, int e, int id, int n) {
	if (s == e) {
		seg[n] = 0;
		return;
	}
	int m = (s + e) / 2;
	if (id <= m)	upt(s, m, id, n * 2);
	else	upt(m + 1, e, id, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int G, P, g, s = 0;
	cin >> G;
	init(1, G, 1);
	for (cin >> P; P--;) {
		cin >> g;
		int c = find(1, G, 1, g, 1);
		if (c) {
			s++;
			upt(1, G, c, 1);
		}
		else	break;
	}
	cout << s;
}