#include <iostream>
using namespace std;

int main() {
	long long a = 1, i = 1, n;
	cin >> n;
	while (n--) {
		a *= i++;
		while (a % 10 == 0)	a /= 10;
		a %= 1000000;
	}
	cout << a % 10;
}