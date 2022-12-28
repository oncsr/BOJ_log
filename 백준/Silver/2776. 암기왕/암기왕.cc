#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		int n, m, b;
		map<int, int> M;
		for (cin >> n; n--;) {
			cin >> b;
			M[b] = 1;
		}
		for (cin >> m; m--;) {
			cin >> b;
			cout << (bool)M[b] << '\n';
		}
	}
}