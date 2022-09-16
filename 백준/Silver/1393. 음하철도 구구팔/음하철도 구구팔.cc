#include <iostream>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;

int gcd(int a, int b) {
	int temp, n = b, temp2;
	if (n == 0)
		return a;
	while (a % n != 0 || b % n != 0) {
		if (n == b) {
			temp = b;
			n = a % b;
		}
		else {
			temp2 = n;
			n = temp % n;
			temp = temp2;
		}
		if (n <= 1)
			break;
	}
	if (n == 0)
		return 1;
	else
		return n;
}

int main() {
	int xs, ys;
	cin >> xs >> ys;
	int xe, ye, c, d;
	cin >> xe >> ye >> c >> d;
	if (d == 0 && c == 0)
		cout << xe << ' ' << ye << '\n';
	else {
		int dx, dy;
		dx = c / gcd(max(abs(c), abs(d)), min(abs(c), abs(d)));
		dy = d / gcd(max(abs(c), abs(d)), min(abs(c), abs(d)));
		int len = (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye), minlen = len;
		int x = xe, y = ye;
		int min_x = x, min_y = y;
		while (x <= 100 && x >= -100 && y <= 100 && y >= -100) {
			x += dx;
			y += dy;
			len = (xs - x) * (xs - x) + (ys - y) * (ys - y);
			if (len < minlen) {
				minlen = len;
				min_x = x;
				min_y = y;
			}
		}
		cout << min_x << ' ' << min_y << '\n';
	}
}