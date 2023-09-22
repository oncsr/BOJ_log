#include <iostream>
using namespace std;

int phi[1001] = { 0,1 };

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

// 1~n까지의 오렌지 문제 해결
void solve(int n) {
	if (n < 1)	return;
	if (n == 1) {
		cout << "1";
		return;
	}
	if (n == 2) {
		cout << "2 1";
		return;
	}
	if (n == 3) {
		cout << "3 2 3 1";
		return;
	}
	if (n == 4) {
		cout << "4 3 4 3 2 1";
		return;
	}
	if (n % 2 == 0) {
		for (int i = 0; i < phi[n]; i++)	cout << n << ' ' << n - 1 << ' ';
		phi[n - 1] -= phi[n];
		phi[n] = 0;
		int t1 = min(phi[n - 2], phi[n - 1]);
		for (int i = 0; i < t1; i++)	cout << n - 2 << ' ' << n - 1 << ' ';
		phi[n - 1] -= t1;
		phi[n - 2] -= t1;
		if (!phi[n - 1]) {
			if (!phi[n - 2])	solve(n - 3);
			else	solve(n - 2);
		}
		else {
			for (int i = 0; i < phi[n - 1]; i++)	cout << n - 3 << ' ' << n - 1 << ' ';
			phi[n - 3] -= phi[n - 1];
			phi[n - 1] = 0;
			solve(n - 3);
		}
		return;
	}
	else {
		for (int i = 0; i < phi[n - 1]; i++)	cout << n << ' ' << n - 1 << ' ';
		phi[n] -= phi[n - 1];
		phi[n - 1] = 0;
		for (int i = 0; i < phi[n]; i++)	cout << n << ' ' << n - 2 << ' ';
		phi[n - 2] -= phi[n];
		phi[n] = 0;
		if (phi[n - 2])	solve(n - 2);
		else	solve(n - 3);
		return;
	}
}

int main() {
	for (int i = 2; i <= 1000; i++) {
		int G = i, k = 2;
		phi[i] = G;
		while (k * k <= G) {
			if (G % k == 0) {
				while (G % k == 0)	G /= k;
				phi[i] *= (k - 1);
				phi[i] /= k;
			}
			k++;
		}
		if (G != 1) {
			phi[i] *= (G - 1);
			phi[i] /= G;
		}
	}

	int N;
	cin >> N;

	solve(N);

}