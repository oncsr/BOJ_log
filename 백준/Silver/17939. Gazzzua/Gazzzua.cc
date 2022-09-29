#include <iostream>
using namespace std;

int main() {
	int n, s = 0, d[100000]{}, mx = 0, id = 0, clear = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (d[i] > mx) {
			mx = d[i];
			id = i;
		}
	}

	while (clear < n) {
		for (int i = clear; i < id; i++)
			s += mx - d[i];
		mx = 0;
		clear = ++id;
		for (int i = clear; i < n; i++) {
			if (d[i] > mx) {
				mx = d[i];
				id = i;
			}
		}
	}

	cout << s;
}