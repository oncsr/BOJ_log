#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		short a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
}