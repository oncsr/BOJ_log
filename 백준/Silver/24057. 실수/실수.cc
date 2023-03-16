#include <iostream>
using namespace std;
using ll = long long;

struct num {
	ll a, b, c, d;
};

#define in(f)		cin >> (f.a) >> (f.b) >> (f.c) >> (f.d)
#define out(f)		cout<< (f.a) << ' ' << (f.b) << ' ' << (f.c) << ' ' << (f.d) << '\n'

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	num A, B;
	in(A);
	in(B);
	
	num plus, minus, multi, div;
	plus.d = minus.d = multi.d = div.d = A.d;
	if (A.d == 0)	plus.c = minus.c = multi.c = div.c = 0;

	// plus

	plus.a = A.a * B.a;
	plus.b = A.b * B.a + A.a * B.b;
	plus.c = A.c * B.a + A.a * B.c;

	if (plus.c == 0)	plus.d = 0;

	if (plus.b != 0 && plus.c != 0) {
		ll G1 = gcd(abs(plus.b), abs(plus.c));
		G1 = gcd(abs(plus.a), G1);
		plus.a /= G1, plus.b /= G1, plus.c /= G1;
	}
	else if (plus.b == 0 && plus.c == 0) {
		plus.a = 1;
	}
	else if (plus.b == 0) {
		ll G1 = gcd(abs(plus.c), abs(plus.a));
		plus.a /= G1, plus.c /= G1;
	}
	else {
		ll G1 = gcd(abs(plus.b), abs(plus.a));
		plus.a /= G1, plus.b /= G1;
	}
	out(plus);

	// minus

	minus.a = A.a * B.a;
	minus.b = A.b * B.a - A.a * B.b;
	minus.c = A.c * B.a - A.a * B.c;

	if (minus.c == 0)	minus.d = 0;

	if (minus.b != 0 && minus.c != 0) {
		ll G2 = gcd(abs(minus.b), abs(minus.c));
		G2 = gcd(abs(minus.a), G2);
		minus.a /= G2, minus.b /= G2, minus.c /= G2;
	}
	else if (minus.b == 0 && minus.c == 0) {
		minus.a = 1;
	}
	else if (minus.b == 0) {
		ll G2 = gcd(abs(minus.c), abs(minus.a));
		minus.a /= G2, minus.c /= G2;
	}
	else {
		ll G2 = gcd(abs(minus.b), abs(minus.a));
		minus.a /= G2, minus.b /= G2;
	}
	out(minus);

	// multi

	multi.a = A.a * B.a;
	multi.b = A.b * B.b + A.c * B.c * A.d;
	multi.c = A.b * B.c + A.c * B.b;

	if (multi.c == 0)	multi.d = 0;

	if (multi.b != 0 && multi.c != 0) {
		ll G3 = gcd(abs(multi.b), abs(multi.c));
		G3 = gcd(abs(multi.a), G3);
		multi.a /= G3, multi.b /= G3, multi.c /= G3;
	}
	else if (multi.b == 0 && minus.c == 0) {
		multi.a = 1;
	}
	else if (multi.b == 0) {
		ll G3 = gcd(abs(multi.c), abs(multi.a));
		multi.a /= G3, multi.c /= G3;
	}
	else {
		ll G3 = gcd(abs(multi.b), abs(multi.a));
		multi.a /= G3, multi.b /= G3;
	}
	out(multi);

	// division

	div.a = A.a * A.a * (B.b * B.b - B.c * B.c * A.d);
	div.b = A.a * A.b * B.a * B.b - A.a * A.c * B.a * B.c * A.d;
	div.c = A.a * A.c * B.a * B.b - A.a * A.b * B.a * B.c;

	if (div.c == 0)	div.d = 0;

	if (div.b != 0 && div.c != 0) {
		ll G4 = gcd(abs(div.b), abs(div.c));
		G4 = gcd(abs(div.a), G4);
		div.a /= G4, div.b /= G4, div.c /= G4;
		if (div.a < 0)	div.a *= -1, div.b *= -1, div.c *= -1;
	}
	else if (div.b == 0 && div.c == 0) {
		div.a = 1;
	}
	else if (div.b == 0) {
		ll G4 = gcd(abs(div.c), abs(div.a));
		div.a /= G4, div.c /= G4;
		if (div.a < 0)	div.a *= -1, div.b *= -1, div.c *= -1;
	}
	else {
		ll G4 = gcd(abs(div.b), abs(div.a));
		div.a /= G4, div.b /= G4;
		if (div.a < 0)	div.a *= -1, div.b *= -1, div.c *= -1;
	}
	out(div);

}