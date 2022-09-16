#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);	cout.tie(0);
	int n, mod = 15746;
	int d[1000001]{ 1 };
	cin >> n;
	d[1] = 1;
	for (int i = 2; i <= n; i++)	d[i] = (d[i - 1] % mod + d[i - 2] % mod) % mod;
	cout << d[n];
}