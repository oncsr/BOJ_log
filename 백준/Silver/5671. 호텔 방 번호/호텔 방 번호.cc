#include <iostream>
using namespace std;

int main() {
	int N, M, s;
	while (cin >> N >> M) {
		s = 0;
		for (int i = N; i <= M; i++) {
			int arr[10]{}, g = i, d = 1, mx = 0;
			while (g) {
				arr[(g % (10 * d)) / d]++;
				mx = max(mx, arr[(g % (10 * d)) / d]);
				g -= (g % (10 * d));
				d *= 10;
			}
			if (mx < 2)	s++;
		}
		cout << s << '\n';
	}
}