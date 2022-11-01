#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1000000]{}, a, b, c, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0) {
			a = arr[i];
			mx = a;
		}
		else if (i == 1) {
			b = arr[i];
			mx = max(b, mx);
		}
		else {
			a = arr[i - 2];
			b = arr[i - 1];
			c = arr[i];
			int d = b + min(a, c);
			mx = max(mx, max(c, d));
		}
	}
	cout << mx;
}