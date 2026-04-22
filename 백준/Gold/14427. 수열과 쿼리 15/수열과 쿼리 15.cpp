#include <iostream>
using namespace std;
using ii = pair<int, int>;

int arr[100001]{};
ii seg[262145]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { s, arr[s] };
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	if (seg[n * 2].second <= seg[n * 2 + 1].second)	seg[n] = seg[n * 2];
	else	seg[n] = seg[n * 2 + 1];
}

void qu(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = { i,v };
		return;
	}
	int m = (s + e) >> 1;
	i <= m ? qu(s, m, i, v, n * 2) : qu(m + 1, e, i, v, n * 2 + 1);
	if (seg[n * 2].second <= seg[n * 2 + 1].second)	seg[n] = seg[n * 2];
	else	seg[n] = seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n,m,a,b;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	init(1, n, 1);
	for (cin >> m; m--;) {
		cin >> a;
		if (a == 1) {
			cin >> a >> b;
			qu(1, n, a, b, 1);
		}
		else	cout << seg[1].first << '\n';
	}
}