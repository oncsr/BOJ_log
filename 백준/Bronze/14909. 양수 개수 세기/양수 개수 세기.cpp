#include <iostream>
using namespace std;

int main() {
	int s = 0, a;
	while (cin >> a)	s += a > 0;
	cout << s;
}