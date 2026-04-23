#include <iostream>
using namespace std;

int main() {
	int T;
	for (cin >> T; T--;) {
		long long a;
		cin >> a;
		cout << (a % 10 ? "0\n" : "1\n");
	}
}