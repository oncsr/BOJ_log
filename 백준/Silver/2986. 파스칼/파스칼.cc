#include <iostream>
using namespace std;

int main() {
	int n, i = 2, f = 0;
	cin >> n;
	for (; i * i <= n; i++)
		if (n % i == 0) {
			f++;
			break;
		}
	
	if (f)	cout << n - n / i;
	else	cout << n - 1;
}