#include <iostream>
using namespace std;
int main() {
	int N, s = 0, a;
	char c;
	for (cin >> N; N--;) {
		cin >> c >> c >> a;
		if (a <= 90)	s++;
	}
	cout << s;
}