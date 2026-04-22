#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		string a;
		cin >> a;
		if (a == "P=NP") {
			cout << "skipped\n";
			continue;
		}
		int n[4]{}, m[4]{}, p1 = 0, p2 = 0, turn = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '+') {
				turn++;
				continue;
			}
			if (!turn)	n[p1++] = a[i] - '0';
			else	m[p2++] = a[i] - '0';
		}
		int A = 0, B = 0, g = 1;
		for (p1--; p1 >= 0; p1--) {
			A += n[p1] * g;
			g *= 10;
		}
		g = 1;
		for (p2--; p2 >= 0; p2--) {
			B += m[p2] * g;
			g *= 10;
		}
		cout << A + B << '\n';
	}
}