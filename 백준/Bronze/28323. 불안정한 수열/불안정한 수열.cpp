#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b, c = 1;
	cin >> n >> a;
	for (int i = 1; i < n; i++) {
		cin >> b;
		if ((a ^ b) & 1)	a = b, c++;
	}
	cout << c;
}