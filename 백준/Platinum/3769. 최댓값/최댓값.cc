#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	ll m, p, a, b, alpha, beta, els;
	double ans = 0, inv = 0;
	for (cin >> T; T--;) {
		cin >> m >> p >> a >> b;
		p /= 2;
		inv = 1.0 / a;
		alpha = (m + a * b) / (a + 1);
		beta = (alpha - b) * a;
		els = m - alpha - beta;
		ans = alpha * pow(a, p) + beta * pow(inv, p);
		ans += (els - 1) * pow(inv, p);
		ans += pow(inv * (els - 1) * (els - 1), p);
		int real = ans + 0.5;
		cout << real << '\n';
	}
}