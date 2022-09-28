#include <iostream>
using namespace std;

int main() {
	string a, b;
	int s = 0, n;
	cin >> a >> n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		s += (a == b);
	}
	cout << s;
}