#include <iostream>
using namespace std;

int main() {
	int n, s = 0;
	cin >> n;
	cout << max(1, n / 2) << '\n';
	for (int i = 1; i <= n; i++)	cout << max(1, i / 2) << ' ';
}