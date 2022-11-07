#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[5]{}, s = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + 5);
	cout << s / 5 << '\n' << a[2];
}