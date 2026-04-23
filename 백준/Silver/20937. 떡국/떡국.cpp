#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int c[50001]{}, n, a, m =0;
	for (cin >> n; n--;) {
		cin >> a;
		c[a]++;
		m = max(m,c[a]);
	}
	cout << m;
}