#include <iostream>
using namespace std;

int main() {
	int n, s = 0;
	cin >> n;
	cout << max(1, n / 2) << "\n1 ";
	for (int i = 2; i <= n; i++)	cout << i / 2 << ' ';
}