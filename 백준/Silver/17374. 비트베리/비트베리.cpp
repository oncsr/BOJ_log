#include <iostream>
using namespace std;
using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		ll P, Q, A, B, C, D;
		cin >> P >> Q >> A >> B >> C >> D;
		Q = Q / C * D;
		ll i = (P - Q) / (A + B);
		ll ans = min(P - A * (i - 1), Q + B * (i - 1));
		ans = max(ans, min(P - A * i, Q + B * i));
		ans = max(ans, min(P - A * (i + 1), Q + B * (i + 1)));
		cout << ans << '\n';
	}
	
}