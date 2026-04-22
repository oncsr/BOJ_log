#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, z = 1, fz = 0, fzz = 0, a, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans += a;
		if (a == 0) {
			if (i == 1)	fz++;
			z++;
		}
		else {
			if (fz) {
				fz = 0;
				fzz = z - 1;
				z = 1;
				continue;
			}
			ans += (z >> 1);
			z = 1;
		}
	}
	if (fz)	ans += (z - 1) >> 1;
	else	ans += ((z + fzz) >> 1);
	cout << ans;
	
}