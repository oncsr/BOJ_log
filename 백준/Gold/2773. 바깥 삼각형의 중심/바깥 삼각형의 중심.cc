#include <iostream>
using namespace std;
struct dot { double x, y; };
int main() {
	int t;
	for (cin >> t; t--;) {
		dot arr[3]{};
		cin >> arr[0].x >> arr[0].y >> arr[1].x >> arr[1].y >> arr[2].x >> arr[2].y;
		dot t1, t2, t3;
		t1.x = arr[0].x + (arr[0].y - arr[1].y);
		t1.y = arr[0].y + (arr[1].x - arr[0].x);
		t2.x = arr[0].x + (arr[2].y - arr[0].y);
		t2.y = arr[0].y + (arr[0].x - arr[2].x);
		t3.x = (t1.x + t2.x) / 2, t3.y = (t1.y + t2.y) / 2;
		
		double d1;
		if (t3.x != arr[0].x)	d1 = (t3.y - arr[0].y) / (t3.x - arr[0].x);
		dot t4, t5, t6;
		t4.x = arr[1].x + (arr[1].y - arr[2].y);
		t4.y = arr[1].y + (arr[2].x - arr[1].x);
		t5.x = arr[1].x + (arr[0].y - arr[1].y);
		t5.y = arr[1].y + (arr[1].x - arr[0].x);
		t6.x = (t4.x + t5.x) / 2, t6.y = (t4.y + t5.y) / 2;
		double d2, x, y;
		if (t6.x != arr[1].x)	d2 = (t6.y - arr[1].y) / (t6.x - arr[1].x);
		else {
			x = t6.x;
			y = d1 * x - d1 * t3.x + t3.y;
		}
		if (t3.x == arr[0].x) {
			x = t3.x;
			y = d2 * x - d2 * t6.x + t6.y;
		}
		else if (t6.x != arr[1].x) {
			double F = d1 * t3.x - d2 * t6.x - t3.y + t6.y;
			x = F / (d1 - d2), y = d1 * x - d1 * t3.x + t3.y;
		}

		cout.setf(ios::fixed);
		cout.precision(4);
		if (x == 0)	cout << "0.0000 ";
		else	cout << x << ' ';
		if (y == 0)	cout << "0.0000\n";
		else	cout << y << '\n';
		cout.unsetf(ios::fixed);
	}
}