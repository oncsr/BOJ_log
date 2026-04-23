#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int Y, M, D, N, a, b, c;
	cin >> Y >> M >> D;
	int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (cin >> N; N--;) {
		int d1 = -1, d2 = -1, d3 = -1;
		cin >> a >> b >> c;
		if (a >= 0 && a <= 99 && b >= 1 && b <= 12 && c >= 1 && c <= 31) {
			if ((a % 4 == 0 && b == 2 && c <= 29) || c <= month_day[b]) {
				if (a > Y)	d1 = 1;
				else if (a == Y) {
					if (b > M)	d1 = 1;
					else if (b == M) {
						if (c >= D)	d1 = 1;
						else	d1 = 0;
					}
					else	d1 = 0;
				}
				else	d1 = 0;
			}
		}
		
		if (c >= 0 && c <= 99 && b >= 1 && b <= 12 && a >= 1 && a <= 31) {
			if ((c % 4 == 0 && b == 2 && a <= 29) || a <= month_day[b]) {
				if (c > Y)	d2 = 1;
				else if (c == Y) {
					if (b > M)	d2 = 1;
					else if (b == M) {
						if (a >= D)	d2 = 1;
						else	d2 = 0;
					}
					else	d2 = 0;
				}
				else	d2 = 0;
			}
		}

		if (c >= 0 && c <= 99 && a >= 1 && a <= 12 && b >= 1 && b <= 31) {
			if ((c % 4 == 0 && a == 2 && b <= 29) || b <= month_day[a]) {
				if (c > Y)	d3 = 1;
				else if (c == Y) {
					if (a > M)	d3 = 1;
					else if (a == M) {
						if (b >= D)	d3 = 1;
						else	d3 = 0;
					}
					else	d3 = 0;
				}
				else	d3 = 0;
			}
		}

		if (d1 == -1 && d2 == -1 && d3 == -1)	cout << "invalid\n";
		else {
			if (d1 != 0 && d2 != 0 && d3 != 0)	cout << "safe\n";
			else	cout << "unsafe\n";
		}
	}

}