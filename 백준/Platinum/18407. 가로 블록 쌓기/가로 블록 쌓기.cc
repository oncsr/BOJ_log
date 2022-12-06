#include <iostream>
#include <algorithm>
using namespace std;
using iii = pair<pair<int, int>, int>;
bool cmp(iii a, iii b) { return a.second < b.second; };
bool cmp2(iii a, iii b) {
	if (a.first.second == b.first.second)	return a.second < b.second;
	return a.first.second < b.first.second;
}
int seg[1048577]{};
int lazy[1048577]{};

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] = lazy[n];
		if (s != e) {
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = 0;
	}
}

void Q(int s, int e, int l, int r, int v, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] = v;
		if (s != e) {
			lazy[n * 2] = v;
			lazy[n * 2 + 1] = v;
		}
		return;
	}
	int m = (s + e) / 2;
	Q(s, m, l, r, v, n * 2);	Q(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, r[200000]{};
	iii arr[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		r[i * 2] = b, r[i * 2 + 1] = b + a - 1;
		arr[i] = { { b, b + a - 1 },i };
	}
	sort(r, r + 2 * N);
	sort(arr, arr + N);
	int s = 0, tmp = r[0], uni = 0, len = 0;
	for (int i = 0; i < N; i++) {
		if (r[s] != arr[i].first.first) {
			while (r[s] != arr[i].first.first) {
				s++;
				if (r[s] == tmp)	uni++;
				tmp = r[s];
			}
		}
		arr[i].first.first = (s + 1) - uni;
		len = max(len, (s + 1) - uni);
	}
	s = 0, tmp = r[0], uni = 0;
	sort(arr, arr + N, cmp2);
	for (int i = 0; i < N; i++) {
		if (r[s] != arr[i].first.second) {
			while (r[s] != arr[i].first.second) {
				s++;
				if (r[s] == tmp)	uni++;
				tmp = r[s];
			}
		}
		arr[i].first.second = (s + 1) - uni;
		len = max(len, (s + 1) - uni);
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) {
		int L = arr[i].first.first, R = arr[i].first.second;
		int V = find(1, len, L, R, 1);
		Q(1, len, L, R, V + 1, 1);
	}
	cout << find(1, len, 1, len, 1);
}