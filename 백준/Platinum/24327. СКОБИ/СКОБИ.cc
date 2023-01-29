#include <iostream>
using namespace std;

int N, M, a, b;
int arr[100001]{}, seg[262145]{};
char t;

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
	if (l > e || r < s)	return arr[b];
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return min(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		if (t == '(')	arr[i] = arr[i - 1] + 1;
		else	arr[i] = arr[i - 1] - 1;
	}
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> a >> b;
		if (arr[b] <= find(1, N, a, b, 1) && arr[a] - arr[a - 1] == 1 && arr[a] - arr[b] == 1)
			cout << "1\n";
		else	cout << "0\n";
	}
}