#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	while (n) {
		if (n == 1)	cout << 0 << '\n';
		else {
			ll i = 2, result = n;
			while (i * i <= n) {
				if (n % i == 0) {
					while (n % i == 0)	n /= i;
					result *= (i - 1);
					result /= i;
				}
				i++;
			}
			if (n != 1) {
				result *= (n - 1);
				result /= n;
			}
			cout << result << '\n';
		}
		cin >> n;
	}
}