#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(a % b, b) : b;
}

int main() {
	ll a, b;
	cin >> a >> b;
	cout << a * b / gcd(a, b);
}