#include <iostream>
using namespace std;
using ll = long long;

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/

int main() {
	ll n, d[10][101]{}, r[10][101]{}, m = 1000000000;
	cin >> n;
	d[0][1] = d[9][1] = 1;
	for (int i = 1; i <= 9; i++)	r[i][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			r[j][i] = (r[j][i - 1] * 2 - d[j][i - 1]) % m;
			if (r[j][i] < 0)	r[j][i] += m;
		}
		for (int j = 1; j <= 8; j++) {
			d[j][i] = (d[j - 1][i - 1] % m + d[j + 1][i - 1] % m) % m;
			if (d[j][i] < 0)	d[j][i] += m;
		}
		d[0][i] = d[9][i] = d[8][i - 1];
	}
	ll s = 0;
	for (int i = 1; i <= 9; i++)	s = (s % m + r[i][n] % m) % m;
	cout << s % m;
}