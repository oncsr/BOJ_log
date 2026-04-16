#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k, s = 0, c = 0;
	cin >> n >> k;
	vector<ll> A(n);
	for (ll& i : A)	cin >> i;
	sort(A.begin(), A.end());
	for (ll& i : A)	s += i * min(c++, k);
	cout << s;
}