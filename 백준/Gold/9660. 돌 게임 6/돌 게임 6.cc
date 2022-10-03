#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	cout << (n % 7 == 0 || n % 7 == 2 ? "CY" : "SK");
}