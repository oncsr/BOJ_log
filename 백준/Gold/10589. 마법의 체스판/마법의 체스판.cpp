#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	cout << n / 2 + m / 2 << '\n';
	for (int i = 2; i <= n; i += 2)	cout << i << " 1 " << i << ' ' << m << '\n';
	for (int i = 2; i <= m; i += 2)	cout << "1 " << i << ' ' << n << ' ' << i << '\n';
}