#include <iostream>
#include <cassert>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (!(n == 1 || n == 4))	cout << " * * *\n";
	else	cout << '\n';
	for (int i = 0; i < 3; i++) {
		if (!(n == 1 || n == 2 || n == 3 || n == 7))	cout << '*';
		else	cout << ' ';
		if (n == 5 || n == 6)	cout << '\n';
		else	cout << "     *\n";
	}
	if (n == 0 || n == 1 || n == 7)	cout << '\n';
	else	cout << " * * *\n";
	for (int i = 0; i < 3; i++) {
		if (n == 0 || n == 2 || n == 6 || n == 8)	cout << '*';
		else	cout << ' ';
		if (n == 2)	cout << '\n';
		else	cout << "     *\n";
	}
	if (!(n == 1 || n == 4 || n == 7))	cout << " * * *";
}