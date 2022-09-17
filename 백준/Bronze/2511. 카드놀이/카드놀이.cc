#include <iostream>
using namespace std;

int main() {
	int arr[10], a = 0, b = 0, c, d = 0;
	for (int i = 0; i < 10; i++)	cin >> arr[i];
	for (int i = 0; i < 10; i++) {
		cin >> c;
		if (c < arr[i])	a += 3, d = 1;
		else if (c > arr[i])	b += 3, d = 2;
		else	a++, b++;
	}
	cout << a << ' ' << b << '\n' << ((a > b) || (a == b && d == 1) ? 'A' : ((a < b) || (a == b && d == 2) ? 'B' : 'D')) << '\n';
}