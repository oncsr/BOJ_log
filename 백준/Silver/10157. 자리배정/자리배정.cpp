#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int x = 1, y = 1, d = 0, r, c, k;
	cin >> r >> c >> k;
	if (k > r * c)	return cout << 0, 0;
	r--, c--;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int cur = 1, rem = c;
	while (cur++ < k) {
		x += dx[d % 4], y += dy[d % 4];
		if (!--rem) {
			if (d >= 2) {
				if (d & 1)	rem = --c;
				else	rem = --r;
			}
			else {
				if (d & 1)	rem = c;
				else	rem = r;
			}
			d++;
		}
		
	}
	cout << x << ' ' << y;

}