#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, d[31] = { 0,0,3,0,11 };
	cin >> n;
	for (int i = 5; i <= n; i++) {
		if (i % 2)	d[i] = 0;
		else	d[i] = d[i - 2] * 3 + (d[i - 2] - d[i - 4]);
	}
	cout << d[n];
}