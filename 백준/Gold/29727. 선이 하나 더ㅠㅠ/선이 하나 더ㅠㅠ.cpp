#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, X1, Y1, X2, Y2;
	cin >> n >> X1 >> Y1 >> X2 >> Y2;
	ll ans = (n * (n + 1) / 2) * (n * (n + 1) / 2);
	if (X1 != X2 && Y1 != Y2) {
		cout << ans;
		return 0;
	}
	ll D;
	if (X1 == X2)	D = min(n, max(Y1, Y2)) - max(-1LL, min(Y1, Y2));
	else	D = min(n, max(X1, X2)) - max(-1LL, min(X1, X2));
	if (D > 0)	ans += (n + 1) * (D * (D - 1) / 2);
	cout << ans;
}