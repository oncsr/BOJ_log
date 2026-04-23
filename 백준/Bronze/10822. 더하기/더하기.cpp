#include <iostream>
using namespace std;

int main() {
	int a;
	char s;
	cin >> a;
	int b = a;
	while (cin >> s >> a)	b += a;
	cout << b;
}