#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, z = 0;
	ll a, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans += a;
		if (a == 0)	z++;
		else	z = 0;
		if (z & 1)	ans++;
	}
	cout << ans;
	
}