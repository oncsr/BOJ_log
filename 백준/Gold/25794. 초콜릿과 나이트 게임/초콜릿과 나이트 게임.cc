#include <iostream>
using namespace std;
#define print cout << cur_x << ' ' << cur_y << '\n'
int main() {
	int x, y;
	cin >> x >> y;
	if (x > y)	swap(x, y);
	if (x == 0) {
		cout << "7\n";
		cout << y << " 0\n";
		cout << y << ' ' << y << '\n';
		cout << y << ' ' << 2 * y << '\n';
		cout << 0 << ' ' << 2 * y << '\n';
		cout << -1*y << ' ' << 2 * y << '\n';
		cout << -1*y << ' ' << y << '\n';
		cout << "0 " << y;
	}
	else {
		if (x == y) {
			cout << "7\n";
			cout << x << ' ' << x << '\n';
			cout << 2 * x << ' ' << 0 << '\n';
			cout << 3 * x << ' ' << -1 * x << '\n';
			cout << 2 * x << ' ' << -2 * x << '\n';
			cout << x << ' ' << -3 * x << '\n';
			cout << "0 " << -2 * x << '\n';
			cout << x << ' ' << -1 * x;
		}
		else {
			cout << "15\n";
			int cur_x = 0, cur_y = 0;
			cur_x += (-1 * y), cur_y += (-1 * x);
			print;
			cur_x += x, cur_y += y;
			print;
			cur_x += (-1 * y), cur_y += x;
			print;
			cur_x += y, cur_y += x;
			print;
			cur_x += (-1 * x), cur_y += y;
			print;
			cur_x += y, cur_y += (-1 * x);
			print;
			cur_x += x, cur_y += y;
			print;
			cur_x += x, cur_y += (-1 * y);
			print;
			cur_x += y, cur_y += x;
			print;
			cur_x += (-1 * x), cur_y += (-1 * y);
			print;
			cur_x += y, cur_y += (-1 * x);
			print;
			cur_x += (-1 * y), cur_y += (-1 * x);
			print;
			cur_x += x, cur_y += (-1 * y);
			print;
			cur_x += (-1 * y), cur_y += x;
			print;
			cur_x += (-1 * x), cur_y += y;
			print;
		}
	}
}