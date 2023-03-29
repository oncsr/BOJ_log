#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	for (cin >> a; a != "0"; cin >> a) {
		bool pal = true;
		int s = 0, e = a.size() - 1;
		while (s <= e) {
			if (a[s] != a[e]) {
				pal = false;
				break;
			}
			s++, e--;
		}
		cout << (pal ? "yes" : "no") << '\n';
	}
}