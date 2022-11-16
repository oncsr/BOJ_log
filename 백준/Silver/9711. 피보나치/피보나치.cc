#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		ll d[10001]{}, p, q;
		cin >> p >> q;
		d[1] = d[2] = 1;
		cout << "Case #" << i << ": ";
		for (int i = 3; i <= p; i++)
			d[i] = (d[i - 1] + d[i - 2]) % q;
		cout << d[p] % q << '\n';
	}
}