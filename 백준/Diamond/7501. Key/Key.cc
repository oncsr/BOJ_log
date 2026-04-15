#include <bits/stdc++.h>
using namespace std;

const __int128 chk[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };

__int128 power(__int128 a, __int128 p, __int128 m) {
	if (p == 0)  return 1;
	if (p == 1)  return a;
	__int128 v = power(a, p >> 1, m) % m;
	return (p & 1) ? v * v % m * a % m : v * v % m;
}

int miller_rabin(__int128 n)
{
	// Small or Even number case
	if (n <= 1)	return 0;
	if (n <= 3)	return 1;
	if (!(n & 1))	return 0;

	for (int i = 0; i < 12; i++) {

		__int128 c = n - 1;
		if (chk[i] >= n - 1)    break;
		if (n == chk[i])	return 1;
		int isPrime = 0;


		// c = 2^(k-1)*q  ~  q
		while (!(c & 1)) {
			c >>= 1;
			if (power(chk[i], c, n) == n - 1) { isPrime = 1; break; }
		}
		if (power(chk[i], c, n) == 1)	isPrime = 1;

		// If n is composite number, than return immediately
		if (!isPrime)	return 0;
	}
	return 1;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long long A, B;
	cin >> A >> B;
	for (long long c = A; c <= B; c++) {
		if (!(c & 1))	continue;
		if (c < 15)	cout << c << ' ';
		else {
			if (miller_rabin((__int128)c))	cout << c << ' ';
		}
	}

}