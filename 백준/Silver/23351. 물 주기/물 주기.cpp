#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<int> pot(n, k);
	int day = 1, pos = 0, dir = 0;
	while (1) {
		if (!dir && pos + a - 1 >= n) {
			dir = 1;
			pos = n - 1;
		}
		if (dir && pos - (a - 1) < 0) {
			dir = 0;
			pos = 0;
		}
		if (dir) {
			for (int j = pos; j > pos - a; j--)
				pot[j] += b;
			pos -= a;
		}
		else {
			for (int j = pos; j < pos + a; j++)
				pot[j] += b;
			pos += a;
		}
		for (int i = 0; i < n; i++) {
			pot[i]--;
			if (pot[i] <= 0) {
				cout << day;
				return 0;
			}
		}
		day++;
	}
}