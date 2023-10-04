#include <iostream>
using namespace std;
typedef long long ll;

ll pow(ll r, ll n) {
	if (n == 0)
		return 1;
	else {
		ll g = pow(r, n / 2);
		if (n % 2)
			return g * g * r;
		else
			return g * g;
	}
}

int main() {
	ll N;
	cin >> N;
	ll r = 2, n = 3;
	bool br = true;
	for (; (pow(r, n) - 1) / (r - 1) <= N; r++) {
		while (((pow(r, n) - 1) / (r - 1)) <= N) {
			if ((pow(r, n) - 1) < 0)
				break;
			if (N % ((pow(r, n) - 1) / (r - 1)) == 0) {
				br = false;
				break;
			}
			n++;
		}
		if (!br)
			break;
		n = 3;
	}
	if (!br) {
		ll a = N / ((pow(r, n) - 1) / (r - 1));
		cout << n << '\n';
		for (int i = 0; i < n; i++)
			cout << a * (ll)pow(r, i) << ' ';
	}
	else	cout << "-1\n";
}