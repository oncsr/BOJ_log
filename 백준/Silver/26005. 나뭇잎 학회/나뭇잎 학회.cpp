#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << (n == 1 ? 0 : (n * n + 1) / 2);
}