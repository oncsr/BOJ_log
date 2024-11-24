#include <bits/stdc++.h>
using namespace std;

int m = 10007;
int P(int n, int k) {
	if (k == 0)	return 1;
	if (k == 1)	return n % m;
	int p = P(n, k >> 1);
	if (k & 1)	return p * p % m * n % m;
	return p * p % m;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	cout << (P(4, n - 1) + P(2, n - 1)) % m;

}