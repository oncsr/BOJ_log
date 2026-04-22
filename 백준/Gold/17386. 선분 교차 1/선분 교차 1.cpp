#include <iostream>
using namespace std;
using ll = long long;
using pp = pair<ll, ll>;
#define x first
#define y second

ll ccw(pp a, pp b, pp c) {
	//	vec1 = a -> b
	pp vec1 = { b.x - a.x,b.y - a.y };

	//	vec2 = b -> c
	pp vec2 = { c.x - b.x,c.y - b.y };

	//	outer product of vec1, vec2
	// ccw > 0  : counter-clockwise
	// ccw == 0 : a line
	// ccw < 0  : clockwise
	ll C = (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;

	if (C > 0)	return 1;
	else if (C < 0)	return -1;
	else	return 0;
}

int main() {
	ll a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	pp A = { a,b }, B = { c,d }, C = { e,f }, D = { g,h };
	if (ccw(A, B, C) * ccw(A, B, D) < 0 && ccw(C, D, A) * ccw(C, D, B) < 0)	cout << 1;
	else	cout << 0;
}