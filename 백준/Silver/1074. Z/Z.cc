#include <iostream>
#include <cmath>
using namespace std;

int result = 0;
void Z(int n, int r, int c) {
	if (n == 1)
		result += (2 * r + c);
	else {
		int ch = (2 * (r >= pow(2, n - 1) ? 1 : 0) + (c >= pow(2, n - 1) ? 1 : 0));
		result += (pow(2, 2 * n) / 4) * ch;
		Z(n - 1, (r >= pow(2, n - 1) ? r - pow(2, n - 1) : r), (c >= pow(2, n - 1) ? c - pow(2, n - 1) : c));
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	Z(n, r, c);
	cout << result << '\n';
}