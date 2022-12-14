#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct node { ll x, y, w; };
struct sp { ll sum, left, right, total; };
int n;

vector<sp> seg(8193);

bool x_incr(node a, node b) {
	if (a.x == b.x)	return a.y < b.y;
	return a.x < b.x;
}

bool y_incr(node a, node b) {
	if (a.y == b.y)	return a.x < b.x;
	return a.y < b.y;
}

sp merge(sp a, sp b) {
	sp c;
	c.sum = a.sum + b.sum;
	c.left = max(a.left, a.sum + b.left);
	c.right = max(a.right + b.sum, b.right);
	c.total = max({ a.total, b.total, a.right + b.left });
	return c;
}

void query(int s, int e, int i, ll v, int n) {
	if (s == e) {
		ll temp = seg[n].sum;
		seg[n] = { v + temp, v + temp, v + temp, v + temp };
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, v, n * 2);
	else	query(m + 1, e, i, v, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	node arr[3000]{};
	vector<vector<node> > take(3001);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i].x >> arr[i].y >> arr[i].w;


	sort(arr, arr + n, x_incr);
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


	sort(arr, arr + n, y_incr);
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
		take[id].push_back(arr[i]);
	}

	ll mx = -1000000000LL * 3000 - 1;
	for (int i = 1; i <= id; i++) {
		seg = vector<sp>(8193);
		for (const node j : take[i]) {
			query(1, n, j.x, j.w, 1);
		}
		mx = max(mx, seg[1].total);
		for (int j = i + 1; j <= id; j++) {
			for (const node k : take[j]) {
				query(1, n, k.x, k.w, 1);
			}
			mx = max(mx, seg[1].total);
		}
	}
	cout << mx;
}