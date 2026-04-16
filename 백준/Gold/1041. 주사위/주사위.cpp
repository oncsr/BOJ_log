#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, A[6]{};
	cin >> n;
	for (int i = 0; i < 6; i++) cin >> A[i];

	if (n == 1) {
		ll s = 0, x = 0;
		for (ll i : A) {
			x = max(x, i);
			s += i;
		}
		return cout << s - x, 0;
	}

	ll mn1 = 51;
	for (ll i : A) mn1 = min(mn1, i);

	ll mn2 = 101;
	mn2 = min({ A[0] + min({A[1],A[2],A[3],A[4]}), A[1] + min({A[2],A[3],A[5]}), A[2] + A[4], A[2] + A[5], A[3] + A[4], A[3] + A[5], A[4] + A[5] });

	ll mn3 = 151;
	mn3 = min({ A[0] + A[3] + A[4], A[0] + A[1] + A[3], A[0] + A[1] + A[2], A[0] + A[2] + A[4], A[1] + A[3] + A[5], A[1] + A[2] + A[5], A[2] + A[4] + A[5], A[3] + A[4] + A[5] });

	ll ans = ((n - 2)*(n - 1) * 4 + (n - 2)*(n - 2))*mn1 + ((n - 1) * 4 + (n - 2) * 4)*mn2 + 4 * mn3;
	cout << ans;

}