#include <iostream>
#include <map>
using namespace std;
using ll = long long;

ll n, p, q;

ll recur(ll n) {
	static map<ll, ll> M;
	if (n == 0)	return 1;
	if (!M[n / p])	M[n / p] = recur(n / p);
	if (!M[n / q])	M[n / q] = recur(n / q);
	return M[n / p] + M[n / q];
}

int main() {
	cin >> n >> p >> q;
	cout << recur(n);
}