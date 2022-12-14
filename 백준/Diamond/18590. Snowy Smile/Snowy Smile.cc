#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

/*
* 2022.12.14
* [used algorithm]
* => segtree, coord_compression, sweeping
* [point]
* => 금광세그 응용 문제
*/

struct dot { int x, y, w; };
struct node { ll sum, left, right, total; };

int n;

bool x_inc(dot a, dot b) {
	if (a.x == b.x)	return a.y < b.y;
	return a.x < b.x;
}

bool y_inc(dot a, dot b) {
	if (a.y == b.y)	return a.x < b.x;
	return a.y < b.y;
}

vector<node> seg(4097);

node merge(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;
	c.left = max(a.left, a.sum + b.left);
	c.right = max(a.right + b.sum, b.right);
	c.total = max({ a.total, b.total, a.right + b.left });
	return c;
}

void query(int s, int e, int i, ll v, int n) {
	if (s == e) {
		ll t = seg[n].sum;
		seg[n] = { v + t,v + t,v + t,v + t };
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, v, n * 2);
	else	query(m + 1, e, i, v, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		cin >> n;
		vector<dot> arr(n);
		for (int i = 0; i < n; i++)	cin >> arr[i].x >> arr[i].y >> arr[i].w;
		sort(arr.begin(), arr.end(), x_inc);
		ll id = 0, temp = -1000000001;
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
		vector<vector<dot> > take(2001);
		sort(arr.begin(), arr.end(), y_inc);
		id = 0, temp = -1000000001;
		for (int j = 0; j < n; j++) {
			if (temp == arr[j].y) {
				temp = arr[j].y;
				arr[j].y = id;
			}
			else {
				temp = arr[j].y;
				arr[j].y = ++id;
			}
			take[id].push_back(arr[j]);
		}

		ll mx = 0;
		for (int g = 1; g <= id; g++) {
			if (take[g].empty())	continue;
			seg = vector<node>(4097);
			for (const dot j : take[g]) {
				query(1, n, j.x, j.w, 1);
			}
			mx = max(mx, seg[1].total);
			for (int j = g + 1; j <= id; j++) {
				if (take[j].empty())	break;
				for (const dot k : take[j]) {
					query(1, n, k.x, k.w, 1);
				}
				mx = max(mx, seg[1].total);
			}
		}
		cout << mx << '\n';
	}
}