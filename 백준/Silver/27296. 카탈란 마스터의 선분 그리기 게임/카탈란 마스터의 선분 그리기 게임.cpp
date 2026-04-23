#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	ll n;
	for (cin >> t; t--;) {
		cin >> n;
		if (n < 2)	cout << "1 0\n";
		else	cout << "0 1\n";
	}
}