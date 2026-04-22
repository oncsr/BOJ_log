#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll d4[1001] = { 0,1,3 };
	ll d3[61] = { 0,1,3 };
	for (int i = 3; i < 61; i++)	d3[i] = d3[i - 1] * 2 + 1;
	int a = 1, b = 1;
	for (int i = 3; i <= 1000; i++) {
		if (i != 3) {
			if (d4[a + 1] - d4[a] < d3[b + 1] - d3[b])
				a++;
			else
				b++;
		}
		d4[i] = 2 * (d4[a] + d3[b]) + 1;
	}
	int T, t = 1;
	while (cin >> T)
		cout << "Case " << t++ << ": " << d4[T] << '\n';
}