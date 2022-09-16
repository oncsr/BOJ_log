#include <iostream>
#include <cmath>
#define dig(a)	a % 9
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k, m;
		cin >> k >> m;

		int g = (m % 9 == 0 ? 9 : m % 9);
		m %= 9;
		int xx, yy, t;
		if (k == 1)
			xx = 0, yy = 1;
		else if (k == 2)
			xx = g, yy = 1;
		else {
			if (m == 0 || m == 3 || m == 6) {
				t = (k - 2) % 4;
				if (t == 0)
					xx = g, yy = 1;
				else if (t == 1)
					xx = g, yy = -8;
				else if (t == 2)
					xx = g-9, yy = -8;
				else
					xx = g-9, yy = 1;
			}
			else if (m == 1 || m == 8) {
				if (k % 4 == 2)
					xx = g, yy = 1;
				else if (k % 4 == 3)
					xx = g, yy = 0;
				else if (k % 4 == 0)
					xx = 0, yy = 0;
				else
					xx = 0, yy = 1;
			}
			else if (m == 2 || m == 7) {
				t = ((k - 2) % 12) / 2;
				if (m == 2) {
					int d[6] = { 2,-6,-1,-3,5,0 };
					xx = d[t];
				}
				else {
					int d[6] = { 7,6,10,3,4,0 };
					xx = d[t];
				}
				int e[6] = { -3,4,3,7,0,1 };
				t = ((k - 3) % 12) / 2;
				yy = e[t];
			}
			else {
				t = ((k - 2) % 12) / 2;
				if (m == 4) {
					int d[6] = { 4,3,10,6,7,0 };
					xx = d[t];
				}
				else {
					int d[6] = { 5,-3,-1,-6,2,0 };
					xx = d[t];
				}
				int e[6] = { -6,-2,-3,4,0,1 };
				t = ((k - 3) % 12) / 2;
				yy = e[t];
			}
		}
		cout << xx << ' ' << yy << '\n';
	}
}