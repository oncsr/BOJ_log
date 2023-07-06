#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

ll N, P, Q, X, Y;
unordered_map<ll, ll> M;

ll solve(ll n) {
	if (n <= 0)	return 1;
	ll L = n / P - X, R = n / Q - Y;
	if (!M[L])	M[L] = solve(L);
	if (!M[R])	M[R] = solve(R);
	return M[L] + M[R];
}

int main() {
	cin >> N >> P >> Q >> X >> Y;
	cout << solve(N);
}