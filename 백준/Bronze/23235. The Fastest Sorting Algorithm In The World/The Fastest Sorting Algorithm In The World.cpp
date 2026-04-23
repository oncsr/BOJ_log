#include <iostream>
using namespace std;

int main() {
	int a, b, c = 1;
	cin >> a;
	while (a) {
		while (a--)	cin >> b;
		cout << "Case " << c++ << ": Sorting... done!\n";
		cin >> a;
	}
}