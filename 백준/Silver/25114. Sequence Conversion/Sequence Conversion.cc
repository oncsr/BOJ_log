#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a[1000000]{}, b[1000000]{}, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			int t = a[i] ^ b[i];
			a[i + 1] ^= t;
			s++;
		}
	}
	cout << (a[n - 1] == b[n - 1] ? s : -1);
}