#include <iostream>
using namespace std;

int main() {
	int n, i = 1;
	cin >> n;
	while (n) {
		cout << i++ << ". ";
		n *= 3;
		cout << (n % 2 ? "odd " : "even ") << n / 6 << '\n';
		cin >> n;
	}
}