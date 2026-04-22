#include <iostream>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int p = a.size(), q = b.size();
	int i = 0;
	for (; i < min(p, q); i++)
		if (a[i] != b[i])	break;
	cout << p + q - i - i;
}