#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n, a, d[68] = { 1,1,2,4 };
	for (int i = 4; i <= 67; i++)	d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];
	for (cin >> n; n--;) {
		cin >> a;
		cout << d[a] << '\n';
	}
}