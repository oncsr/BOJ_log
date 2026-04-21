#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

double area(vector<pair<double, double>> V) {
	double ans = 0;
	int N = V.size();
	for (int i = 0; i < N; i++)
		ans += (V[i].x * (V[(i + 1) % N].y - V[(i + N - 1) % N].y));
	return abs(ans) / 2;
}

int gcd(int a, int b) {
	if (!a)	return b;
	if (!b)	return a;
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int a, b, c, d, e, f;
	for (cin >> a >> b >> c >> d >> e >> f; a || b || c || d || e || f; cin >> a >> b >> c >> d >> e >> f) {
		vector<pair<double, double>> tri = { {a,b},{c,d},{e,f} };
		double A = area(tri);
		
		int B = gcd(abs(c - a), abs(d - b)) + gcd(abs(e - c), abs(f - d)) + gcd(abs(a - e), abs(b - f));
		double d1 = ((double)d - b) / (c - a), d2 = ((double)f - d) / (e - c);
		if (d1 == d2) {
			cout << 0 << '\n';
			continue;
		}
		cout << (int)(A - (double)B / 2 + 1) << '\n';

	}

}