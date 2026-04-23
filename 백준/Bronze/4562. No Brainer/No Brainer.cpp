#include <iostream>
using namespace std;
int main() {
	int t, a, b;
	for (cin >> t; t--;) {
		cin >> a >> b;
		cout << (a < b ? "NO BRAINS\n" : "MMM BRAINS\n");
	}
}