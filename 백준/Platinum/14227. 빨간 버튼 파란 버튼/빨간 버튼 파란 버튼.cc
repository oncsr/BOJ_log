#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt = 0;
	int temp = 0, tempcnt = 0;
	if (a > c || b > d || ((c % 2 != d % 2) && (c - a != d - b)))
		cout << -1 << '\n';
	else if ((c % 2 != d % 2) && (c - a == d - b)) {
		cout << c - a << '\n';
	}
	else {
		while (a != c) {
			if (c - a == d - b) {
				temp = c - a;
				tempcnt = cnt;
			}
			if (c % 2 == 0 && d % 2 == 0 && c / 2 >= a) {
				c /= 2;
				d /= 2;
			}
			else {
				c--;
				d--;
			}
			cnt++;
		}
		if (d != b)
		{
			if (temp == 0)
				cout << -1 << '\n';
			else
				cout << tempcnt + temp << '\n';
		}
		else
			cout << cnt << '\n';
	}
}