#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> M;
	int n, m, a, s = 0;
	for (cin >> n >> m; n--;) {
		cin >> a;
		M[a]++;
		s++;
	}
	for (; m--;) {
		cin >> a;
		M[a] ? s-- : s++;
	}
	cout << s;
}