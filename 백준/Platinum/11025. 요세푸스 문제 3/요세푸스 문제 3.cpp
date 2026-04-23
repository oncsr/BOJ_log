#include <iostream>
using namespace std;

int main() {
	int n, k, s = 1;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		s = (s + k) % (i + 1);
		if (!s)	s = i + 1;
	}
	cout << s;
}