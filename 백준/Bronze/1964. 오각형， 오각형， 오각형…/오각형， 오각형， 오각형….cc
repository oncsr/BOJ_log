#include <iostream>
using namespace std;
int main() {
	int n, ans = 1, d = 4;
	cin >> n;
	while (n--) {
		ans += d;
		d += 3;
		ans %= 45678;
	}
	cout << ans;
}