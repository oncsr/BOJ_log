#include <iostream>
using namespace std;
typedef long long ll;

ll comb(int a, int b) {
	ll s1 = 1, s2 = 1;
	int j = b;
	for (int i = 0; i < j; i++) {
		s1 *= a--;
		s2 *= b--;
	}
	return s1 / s2;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	int r = m - 1;
	int p = m - n;
	if (p > r / 2)
		p = r - p;
	ll s = comb(r, p);
	cout << s << '\n';
}