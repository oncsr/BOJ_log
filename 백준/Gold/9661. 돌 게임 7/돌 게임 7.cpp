#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	n %= 5;
	cout << (n == 0 || n == 2 ? "CY" : "SK");
}