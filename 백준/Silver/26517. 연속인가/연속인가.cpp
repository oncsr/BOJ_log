#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll k, a, b, c, d;
	cin >> k >> a >> b >> c >> d;
	if (a * k + b == c * k + d)	cout << "Yes " << a * k + b;
	else	cout << "No";
}