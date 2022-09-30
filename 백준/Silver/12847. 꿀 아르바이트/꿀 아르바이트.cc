#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	ll a[100000]{}, s = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		if (i >= m - 1) {
			mx = max(s, mx);
			s -= a[i - (m - 1)];
		}
	}
	cout << mx;
}