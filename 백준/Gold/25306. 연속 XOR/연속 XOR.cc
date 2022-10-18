#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	if (a % 2)	ans ^= a;
	else		a--;
	for (ll i = a + ((b - a) / 4) * 4 + 1; i <= b; i++)
		ans ^= i;
	cout << ans << '\n';
}