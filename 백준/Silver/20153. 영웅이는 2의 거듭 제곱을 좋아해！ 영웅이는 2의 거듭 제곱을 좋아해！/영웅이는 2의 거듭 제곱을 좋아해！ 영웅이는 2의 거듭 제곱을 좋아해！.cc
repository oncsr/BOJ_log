#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a[2222222]{}, s = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s ^= a[i];
	}
	m = s;
	for (int i = 0; i < n; i++)	m = max(m, s ^ a[i]);
	cout << m << m;
}