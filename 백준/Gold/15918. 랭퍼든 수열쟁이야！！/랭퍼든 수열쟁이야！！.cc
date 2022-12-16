#include <iostream>
using namespace std;

int s = 0, n, x, y, skip;
int arr[25]{};
void B(int k) {
	if (k == skip)	B(k + 1);
	if (k == n && skip != n) {
		for (int i = 1; i <= 2 * n; i++) {
			if (!arr[i]) {
				if (!arr[i]) {
					if (i + k + 1 <= 2 * n && !arr[i + k + 1])	s++;
					return;
				}
			}
		}
		return;
	}
	if (k == n - 1 && skip == n) {
		for (int i = 1; i <= 2 * n; i++) {
			if (!arr[i]) {
				if (i + k + 1 <= 2 * n && !arr[i + k + 1])	s++;
				return;
			}
		}
		return;
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!arr[i]) {
			if (i + k + 1 <= 2 * n && !arr[i + k + 1]) {
				arr[i] = arr[i + k + 1] = k;
				B(k + 1);
				arr[i] = arr[i + k + 1] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> x >> y;
	arr[x] = arr[y] = skip = y - x - 1;
	B(1);
	cout << s;
}