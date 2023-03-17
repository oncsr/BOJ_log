#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, bool> M;
	string a;
	int n, m, s = 0;
	for (cin >> n >> m; n--;) {
		cin >> a;
		M[a] = true;
	}
	for (; m--;) {
		cin >> a;
		s += (M[a] ? 1 : 0);
	}
	cout << s;
}