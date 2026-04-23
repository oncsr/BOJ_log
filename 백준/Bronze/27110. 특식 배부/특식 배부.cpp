#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << min(n, a) + min(n, b) + min(n, c);
}