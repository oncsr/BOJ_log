#include <iostream>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	int s = 1, e = N, m = (s + e) >> 1;
	while (s <= e) {
		cout << "? " << m << endl;
		cin >> a;
		if (!a) {
			cout << "= " << m << endl;
			return 0;
		}
		if (a > 0)	e = m - 1;
		else	s = m + 1;
		m = (s + e) >> 1;
	}
}