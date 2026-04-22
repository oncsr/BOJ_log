#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int E;
		ld a, b;
		pair<ld, ld> ans;
		cin >> E >> a >> b;
		if (E == 1) {
			ld R = sqrt(a * a + b * b);
			ld T;
			if (a == 0) {
				if (b == 0)	T = 0;
				else if (b > 0)	T = M_PI / 2.;
				else	T = M_PI * 3. / 2.;
			}
			else {
				if (a < 0 && b < 0)	T = M_PI + atan(b / a);
				else if (a < 0) {
					T = atan(b / abs(a));
					T = M_PI - T;
				}
				else if (b < 0) {
					T = atan(abs(b) / a);
					T = M_PI * 2. - T;
				}
				else	T = atan(b / a);
			}
			ans = { R,T };
		}
		else {
			ld A, B;
			if (b == M_PI / 2.)	A = 0, B = a;
			else if (b == M_PI * 3. / 2.)	A = 0, B = -a;
			else {
				A = a / sqrt(1. + tan(b) * tan(b));
				B = A * abs(tan(b));
				if (b > M_PI / 2. && b < M_PI * 3. / 2.)	A *= -1;
				if (b > M_PI)	B *= -1;
			}
			ans = { A,B };
		}
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << ans.first << ' ' << ans.second << '\n';
		cout.unsetf(ios::fixed);
	}
}