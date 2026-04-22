#include <iostream>
#include <algorithm>
using namespace std;
using ld = long double;
using dd = pair<ld, ld>;
#define x first
#define y second

ld area1(dd a, dd b) {
	return (max(a.x, b.x) - min(a.x, b.x)) * (max(a.y, b.y) - min(a.y, b.y)) / 2.0;
}

ld area2(dd a, dd b, dd c) {
	dd arr[3] = { a,b,c };
	sort(arr, arr + 3);
	a = arr[0], b = arr[1], c = arr[2];
	ld maxx = max({ a.x, b.x, c.x }), minx = min({ a.x, b.x, c.x });
	ld maxy = max({ a.y, b.y, c.y }), miny = min({ a.y, b.y, c.y });
	ld X = maxx - minx;
	ld Y = maxy - miny;
	ld S = X * Y;
	ld S1 = area1(a, b);
	ld S2 = area1(b, c);
	ld S3 = area1(c, a);
	if (a.y < b.y && b.y < c.y) {
		ld d1 = (b.y - a.y) / (b.x - a.x);
		ld d2 = (c.y - a.y) / (c.x - a.x);
		if (d1 > d2)	S -= (b.x - a.x) * (c.y - b.y);
		else	S -= (c.x - b.x) * (b.y - a.y);
	}
	if (a.y > b.y && b.y > c.y) {
		ld d1 = (b.y - a.y) / (b.x - a.x);
		ld d2 = (c.y - a.y) / (c.x - a.x);
		if (d1 > d2)	S -= (c.x - b.x) * (a.y - b.y);
		else	S -= (b.x - a.x) * (b.y - c.y);
	}
	return S - S1 - S2 - S3;
}

int main() {
	int N;
	cin >> N;
	dd arr[35]{};
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	ld mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (arr[i].x == arr[j].x && arr[j].x == arr[k].x)	continue;
				if (arr[i].y == arr[j].y && arr[j].y == arr[k].y)	continue;

				mx = max(mx, area2(arr[i], arr[j], arr[k]));
			}
		}
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << mx;
	cout.unsetf(ios::fixed);
}