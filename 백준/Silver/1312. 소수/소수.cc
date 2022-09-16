#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	int g = a % b;
	for (int i = 0; i < n - 1; i++) {
		g *= 10;
		g %= b;
	}
	cout << g * 10 / b;
}