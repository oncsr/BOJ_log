#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<int, bool> M;
	int n, m, a;
	for (cin >> n; n--;) {
		cin >> a;
		M[a] = true;
	}
	for (cin >> m; m--;) {
		cin >> a;
		cout << (M[a] ? "1 " : "0 ");
	}
}