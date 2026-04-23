#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		cout << '@';
		if (i == 0 || i == n + 1) {
			for (int j = 0; j < n; j++)	cout << '@';
		}
		else {
			for (int j = 0; j < n; j++)	cout << ' ';
		}
		cout << "@\n";
	}
}