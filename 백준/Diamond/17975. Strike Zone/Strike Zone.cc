#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct dot { int x, y, w; };
struct node { int sum, left, right, total; };

int n1, n2, c1, c2, i = 0, a, b;

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

void query(int s, int e, int i, int v, int n) {
	if (s == e) {
		int t = seg[n].sum;
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
	cin >> n1;
	dot arr[2000]{};
	for (; i < n1; i++) {
		cin >> a >> b;
		arr[i] = { a,b,1 };
	}
	cin >> n2;
	for (; i < n1 + n2; i++) {
		cin >> a >> b;
		arr[i] = { a,b,-1 };
	}
	cin >> c1 >> c2;
	sort(arr, arr + n1 + n2, x_inc);
	int id = 0, temp = -1000000001;
	for (int j = 0; j < n1 + n2; j++) {
		if (temp == arr[j].x) {
			temp = arr[j].x;
			arr[j].x = id;
		}
		else {
			temp = arr[j].x;
			arr[j].x = ++id;
		}
	}
	vector<vector<dot> > take(2001);
	sort(arr, arr + n1 + n2, y_inc);
	id = 0, temp = -1000000001;
	for (int j = 0; j < n1 + n2; j++) {
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

	int n = n1 + n2, mx = -100000001;
	for (int g = 1; g <= id; g++) {
		if (take[g].empty())	continue;
		seg = vector<node>(4097);
		for (const dot j : take[g]) {
			if (j.w > 0)	query(1, n, j.x, c1, 1);
			else	query(1, n, j.x, -1 * c2, 1);
			mx = max(mx, seg[1].total);
		}
		for (int j = g + 1; j <= id; j++) {
			if (take[j].empty())	break;
			for (const dot k : take[j]) {
				if (k.w > 0)	query(1, n, k.x, c1, 1);
				else	query(1, n, k.x, -1 * c2, 1);
				mx = max(mx, seg[1].total);
			}
		}
	}
	cout << mx;
}