#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (cin >> t; t--;) {
		map<string, double> M;
		int x, y;
		cin >> x >> y;
		string a;
		double b, s = 0;
		for (; x--;) {
			cin >> a >> b;
			M[a] = b;
			s += b;
		}
		vector<string> inv;
		for (; y--;) {
			cin >> a >> b;
			if (!M[a]) {
				inv.push_back(a);
			}
			else {
				s -= (M[a] * b);
			}
		}
		cout << s << '\n';
		if (!inv.empty()) {
			cout << "INVALID COUPONS\n";
			for (string i : inv)	cout << i << '\n';
		}
	}
}