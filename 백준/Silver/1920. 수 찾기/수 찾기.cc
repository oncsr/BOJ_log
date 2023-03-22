#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<int, bool> M;
	int n, m, a;
	for (cin >> n; n--;) {
		cin >> a;
		M[a] = true;
	}
	for (cin >> m; m--;) {
		cin >> a;
		cout << (int)M[a] << '\n';
	}
}