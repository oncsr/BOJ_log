#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int d1[41] = { 1,0,1,1 };
	int d2[41] = { 0,1,1,2 };
	for (int i = 4; i <= 40; i++) {
		d1[i] = d1[i - 1] + d1[i - 2];
		d2[i] = d2[i - 1] + d2[i - 2];
	}
	int T, n;
	for (cin >> T; T--;) {
		cin >> n;
		cout << d1[n] << ' ' << d2[n] << '\n';
	}

}