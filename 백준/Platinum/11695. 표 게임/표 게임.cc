#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, m, a, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll s1 = 0;
		for (int j = 0; j < m; j++) {
			cin >> a;
			s1 += a;
		}
		ans ^= s1;
	}
	cout << (ans ? "august14" : "ainta") << '\n';
}