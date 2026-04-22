#include <iostream>
using namespace std;

int main() {
	int T;
	for (cin >> T; T--;) {
		unsigned int n;
		cin >> n;
		if (n <= 1)	cout << 2 << '\n';
		else {
			while (1) {
				unsigned int g = 2;
				bool find = 1;
				while (g * g <= n) {
					if (n % g == 0) {
						find = 0;
						break;
					}
					g++;
				}
				if (find) {
					cout << n << '\n';
					break;
				}
				n++;
			}
		}
	}
}