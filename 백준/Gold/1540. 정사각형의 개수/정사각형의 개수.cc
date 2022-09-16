#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int g = sqrt(n);
	int ans = (g-1) * g * (2 * g - 1) / 6;
	int mid = (g * g + (g + 1) * (g + 1))/2;
	if (n > mid) {
		ans += (g - 1) * g / 2;
		n -= mid;
	}
	else
		n -= g * g;
	if (n >= 2) {
		int id = 1;
		n -= 2;
		ans += id++;
		while (n--)
			ans += id++;
	}
	cout << ans << '\n';
}