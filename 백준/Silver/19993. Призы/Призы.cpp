#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (min(n, m) == 1) {
		if (max(n, m) <= 2)	cout << 0;
		else	cout << (max(n, m) - 3) / 4 + 1;
	}
	else if (min(n, m) < 3)	cout << 0;
	else	cout << 1;
}