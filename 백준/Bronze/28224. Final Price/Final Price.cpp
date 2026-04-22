#include <iostream>
using namespace std;

int main() {
	int n, s = 0, a;
	for (cin >> n; n--; cin >> a, s += a);
	cout << s;
}