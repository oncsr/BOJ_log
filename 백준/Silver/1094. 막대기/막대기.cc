#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	int x;
	cin >> x;
	int i = 2;
	while (i <= x)
		i *= 2;
	i /= 2;
	for (; x > 0; i /= 2) {
		if (x >= i) {
			cnt++;
			x -= i;
		}
	}
	cout << cnt << '\n';
}