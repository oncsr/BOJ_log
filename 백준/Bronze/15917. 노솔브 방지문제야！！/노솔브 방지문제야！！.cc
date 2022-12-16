#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, a;
	for (cin >> t; t--;) {
		cin >> a;
		cout << ((a & (-a)) == a ? 1 : 0) << '\n';
	}
}