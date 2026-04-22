#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	ll d4[1000001] = { 0,1,3 };
	ll d3[10001] = { 0,1,3 };
	for (int i = 3; i < 10001; i++)	d3[i] = (d3[i - 1] * 2 + 1) % 9901;
	int a = 1, b = 1, g = 1, c = 1;
	for (int i = 3; i <= n; i++) {
		if (i != 3) {
			if (g == c) {
				g++;
				c = 0;
				b++;
			}
			else {
				c++;
				a++;
			}
		}
		d4[i] = (2 * (d4[a] + d3[b]) + 1) % 9901;
	}

	cout << d4[n];
}