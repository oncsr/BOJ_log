#include <iostream>
using namespace std;

//	2022-09-09
// 수학 문제
int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, d;
		cin >> a >> b >> d;
		if (a < b)	swap(a, b);
		if (d % gcd(a, b) == 0)	cout << "Yes\n";
		else	cout << "No\n";
	}
}