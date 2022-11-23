#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if ((n == 1 && k == 1) || n == k)	cout << "Impossible";
	else {
		if (k == n - 1) {
			for (int i = 1; i <= n; i++)	cout << i << ' ';
		}
		else {
			cout << n << ' ';
			int j = 2;
			for (; j < k + 2; j++)	cout << j << ' ';
			cout << 1 << ' ';
			for (; j < n; j++)	cout << j << ' ';
		}
	}
}