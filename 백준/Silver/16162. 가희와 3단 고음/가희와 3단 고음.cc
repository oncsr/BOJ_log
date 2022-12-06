#include <iostream>
using namespace std;

int main() {
	int n, a, d, b, x = 0;
	cin >> n >> a >> d;
	int o = a;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (b == o)	x++, o += d;
	}
	cout << x;
}