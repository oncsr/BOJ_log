#include <iostream>
using namespace std;

int main() {
	int n, l, c;
	cin >> n >> l >> c;
	int g = (c + 1) / (l + 1);
	if (g % 13 == 0)	g -= 1;
	int ans = n / g + 1;
	n -= (ans - 1) * g;
	if (n % 13 == 0 && n != 0)
		if ((n + 1) * (l + 1) - 1 > c || ans == 1 || g % 13 == 1)	ans++;
	cout << (n ? ans : ans - 1);
}