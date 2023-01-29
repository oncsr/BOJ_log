#include <iostream>
using namespace std;

int seg[262145]{};
int arr[100001]{};
string a;
int N, M, x, y, s = 0;

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return arr[y];
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return min(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> M;
	N = a.size();
	for (int i = 0; i < N; i++) {
		if (a[i] == '(')	arr[i + 1] = arr[i] + 1;
		else	arr[i + 1] = arr[i] - 1;
	}
	init(1, N, 1);
	for (; M--;) {
		cin >> x >> y;
		if (arr[y] <= find(1, N, x, y, 1) && arr[x] - arr[y] == 1 && arr[x] == arr[x - 1] + 1)	s++;
	}
	cout << s;
}