#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
using ld = long double;

struct coord {
	ld x, y, z;
};

coord _1_2(coord a) {
	ld R, O, Z;
	R = sqrt(a.x * a.x + a.y * a.y);
	if (a.x == 0) {
		if (a.y == 0)	O = 0;
		else if (a.y > 0)	O = M_PI / 2.;
		else	O = M_PI * 3. / 2.;
	}
	else {
		if (a.x < 0 && a.y < 0)	O = M_PI + atan(a.y / a.x);
		else if (a.x < 0) {
			O = atan(a.y / abs(a.x));
			O = M_PI - O;
		}
		else if (a.y < 0) {
			O = atan(abs(a.y) / a.x);
			O = M_PI * 2. - O;
		}
		else	O = atan(a.y / a.x);
	}
	Z = a.z;
	return { R,O,Z };
}

coord _1_3(coord a) {
	ld P, T, O;
	P = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	if (P == 0)	T = 0;
	else	T = acos(a.z / P);
	if (T > M_PI)	T = M_PI * 2. - T;
	if (a.x == 0) {
		if (a.y == 0)	O = 0;
		else if (a.y > 0)	O = M_PI / 2.;
		else	O = M_PI * 3. / 2.;
	}
	else {
		if (a.x < 0 && a.y < 0)	O = M_PI + atan(a.y / a.x);
		else if (a.x < 0) {
			O = atan(a.y / abs(a.x));
			O = M_PI - O;
		}
		else if (a.y < 0) {
			O = atan(abs(a.y) / a.x);
			O = M_PI * 2. - O;
		}
		else	O = atan(a.y / a.x);
	}
	return { P,T,O };
}

coord _2_1(coord a) {
	ld A, B, C;
	C = a.z;
	if (a.y == M_PI / 2.)	A = 0, B = a.x;
	else if (a.y == M_PI * 3. / 2.)	A = 0, B = -a.x;
	else {
		A = a.x / sqrt(tan(a.y) * tan(a.y) + 1.);
		B = abs(A * tan(a.y));
		if (a.y > M_PI / 2. && a.y < M_PI * 3. / 2.)	A *= -1;
		if (a.y > M_PI)	B *= -1;
	}
	return { A,B,C };
}

coord _3_1(coord a) {
	ld A, B, C;
	if (a.x == 0)	A = 0, B = 0, C = 0;
	else {
		C = a.x * cos(a.y);
		if (a.z == M_PI / 2.)	A = 0, B = sqrt((a.x * a.x - C * C));
		else if (a.z == M_PI * 3. / 2.)	A = 0, B = -sqrt((a.x * a.x - C * C));
		else {
			A = sqrt((a.x * a.x - C * C) / (1. + tan(a.z) * tan(a.z)));
			B = abs(A * tan(a.z));
			if (a.z > M_PI / 2. && a.z < M_PI * 3. / 2.)	A *= -1;
			if (a.z > M_PI)	B *= -1;
		}
	}
	return { A,B,C };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int S, E;
		ld a, b, c;
		cin >> S >> E >> a >> b >> c;
		coord ans = { a,b,c };
		if (S == 1) {
			if (E == 2)	ans = _1_2(ans);
			else	ans = _1_3(ans);
		}
		if (S == 2) {
			if (E == 1)	ans = _2_1(ans);
			else {
				ans = _2_1(ans);
				ans = _1_3(ans);
			}
		}
		if (S == 3) {
			if (E == 1)	ans = _3_1(ans);
			else {
				ans = _3_1(ans);
				ans = _1_2(ans);
			}
		}
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << ans.x << ' ' << ans.y << ' ' << ans.z << '\n';
		cout.unsetf(ios::fixed);
	}

}