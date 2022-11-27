#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, len;
	cin >> n;
	len = log10(n) + 1;
	bool no = true;
	for (int i = max(1, n - len * 9); i < n; i++) {
		int temp = i, sum = i, leng = log10(i);
		int g = pow(10, leng);
		while (g > 0) {
			sum += temp / g;
			temp -= temp / g * g;
			g /= 10;
		}
		if (sum == n) {
			cout << i;
			no = false;
			break;
		}
	}
	if (no)	cout << 0;
}