#include <iostream>
using namespace std;

int main() {
	int N, c = 0, i = 666;
	cin >> N;
	while (c < N) {
		int d = 0, t = i, g = 10;
		while (t > 0) {
			int temp = t % g;
			if (temp == 6 * (g / 10))	d++;
			else	d = 0;
			t -= temp;
			g *= 10;
			if (d >= 3) {
				c++;
				break;
			}
		}
		i++;
	}
	cout << i - 1;
}