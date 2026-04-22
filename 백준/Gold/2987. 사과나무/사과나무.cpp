#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ld = long double;
using dd = pair<ld, ld>;
#define x first
#define y second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<dd> V;
	for (int i = 0; i < 3; i++) {
		ld a, b;
		cin >> a >> b;
		V.push_back({ a,b });
	}
	sort(V.begin(), V.end());
	ld area = 0;
	area += V[0].x * (V[1].y - V[2].y);
	area += V[1].x * (V[2].y - V[0].y);
	area += V[2].x * (V[0].y - V[1].y);
	area = abs(area) / 2;
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << area << '\n';
	cout.unsetf(ios::fixed);
	int N, ans = 0;
	for (cin >> N; N--;) {
		ld a, b;
		cin >> a >> b;
		ld d2 = (V[2].y - V[0].y) / (V[2].x - V[0].x);
		if (a < V[0].x)	continue;
		else if (a < V[1].x) {
			ld d1 = (V[1].y - V[0].y) / (V[1].x - V[0].x);
			ld val1 = d1 * (a - V[0].x) + V[0].y;
			ld val2 = d2 * (a - V[0].x) + V[0].y;
			if (val1 > val2)	swap(val1, val2);
			if (val1 <= b && b <= val2)	ans++;
		}
		else if (a < V[2].x) {
			if (V[0].x == V[1].x && a == V[1].x) {
				ld val1 = V[0].y, val2 = V[1].y;
				if (val1 > val2)	swap(val1, val2);
				if (val1 <= b && b <= val2)	ans++;
				continue;
			}
			ld d1 = (V[2].y - V[1].y) / (V[2].x - V[1].x);
			ld val1 = d1 * (a - V[1].x) + V[1].y;
			ld val2 = d2 * (a - V[0].x) + V[0].y;
			if (val1 > val2)	swap(val1, val2);
			if (val1 <= b && b <= val2)	ans++;
		}
		else {
			if (a == V[2].x) {
				if (V[1].x == V[2].x) {
					ld val1 = V[1].y, val2 = V[2].y;
					if (val1 > val2)	swap(val1, val2);
					if (val1 <= b && b <= val2)	ans++;
				}
				else {
					if (b == V[2].y)	ans++;
				}
			}
		}
	}
	cout << ans;
}