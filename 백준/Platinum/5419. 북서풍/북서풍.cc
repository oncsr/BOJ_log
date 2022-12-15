#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> seg(262145);
int n, a, b;
struct dot { int x, y; };

bool x_inc(dot a, dot b) {
	if (a.x == b.x)	return a.y < b.y;
	return a.x > b.x;
}

bool y_inc(dot a, dot b) {
	if (a.y == b.y)	return a.x < b.x;
	return a.y < b.y;
}

void query(int s, int e, int i, int n) {
	if (s == e) {
		seg[n]++;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, n * 2);
	else	query(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		seg = vector<ll>(262145);
		cin >> n;
		vector<dot> arr;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			arr.push_back({ a,b });
		}
		sort(arr.begin(), arr.end(), x_inc);
		
		int id = 0, temp = -1000000001;
		for (int i = 0; i < n; i++) {
			if (temp == arr[i].x) {
				temp = arr[i].x;
				arr[i].x = id;
			}
			else {
				temp = arr[i].x;
				arr[i].x = ++id;
			}
		}
		sort(arr.begin(), arr.end(), y_inc);
		id = 0, temp = -1000000001;
		for (int i = 0; i < n; i++) {
			if (temp == arr[i].y) {
				temp = arr[i].y;
				arr[i].y = id;
			}
			else {
				temp = arr[i].y;
				arr[i].y = ++id;
			}
		}

		ll s = 0;
		for (int i = 0; i < n; i++) {
			s += find(1, n, 1, arr[i].x, 1);
			query(1, n, arr[i].x, 1);
		}
		cout << s << '\n';
	}
}