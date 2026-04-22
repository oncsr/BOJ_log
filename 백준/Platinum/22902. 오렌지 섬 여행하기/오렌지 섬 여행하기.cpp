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
	if (n % 2 == 0) {
		int it = min(phi[n - 1], phi[n]);
		for (int i = 0; i < it; i++)	cout << n << ' ' << n - 1 << ' ';
		phi[n - 1] -= it;
		phi[n] -= it;

		int t1 = min(phi[n - 2], phi[n - 1]);
		for (int i = 0; i < t1; i++)	cout << n - 2 << ' ' << n - 1 << ' ';
		phi[n - 1] -= t1;
		phi[n - 2] -= t1;
		if (!phi[n - 1]) {
			if (!phi[n - 2])	solve(n - 3);
			else	solve(n - 2);
		}
		else {
			int i = 2;
			for (; n - 1 - i > 1; i++) {
				if (gcd(n - 1, n - i - 1) != 1)	continue;
				int it = min(phi[n - 1], phi[n - 1 - i]);
				for (int k = 0; k < it; k++)	cout << n - 1 - i << ' ' << n - 1 << ' ';
				phi[n - 1] -= it;
				phi[n - 1 - i] -= it;
				if (!phi[n - 1])	break;
			}
			if (!phi[n - 1 - i])	solve(n - 2 - i);
			else	solve(n - 1 - i);
			/*
			for (int i = 0; i < phi[n - 1]; i++)	cout << n - 3 << ' ' << n - 1 << ' ';
			phi[n - 3] -= phi[n - 1];
			phi[n - 1] = 0;
			solve(n - 3);
			*/
		}
		return;
	}
	else {
		int it = min(phi[n], phi[n - 1]);
		for (int i = 0; i < it; i++)	cout << n << ' ' << n - 1 << ' ';
		phi[n] -= it;
		phi[n - 1] -= it;
		if (!phi[n]) {
			if (!phi[n - 1])	solve(n - 2);
			else {
				int i = 2;
				for (; n - i > 1; i++) {
					if (gcd(n - 1, n - i) != 1)	continue;
					int it = min(phi[n - 1], phi[n - i]);
					for (int j = 0; j < it; j++)	cout << n - i << ' ' << n - 1 << ' ';
					phi[n - 1] -= it;
					phi[n - i] -= it;
					if (!phi[n - 1])	break;
				}

				if (!phi[n - i])	solve(n - i - 1);
				else	solve(n - i);
				
			}
		}
		else {
			int i = 2;
			for (; n - i > 1; i++) {
				if (gcd(n, n - i) != 1)	continue;
				int it = min(phi[n], phi[n - i]);
				for (int k = 0; k < it; k++)	cout << n << ' ' << n - i << ' ';
				phi[n - i] -= it;
				phi[n] -= it;
				if (!phi[n])	break;
			}

			if (!phi[n - i])	solve(n - i - 1);
			else {
				int it = min(phi[n - i], phi[n - i - 1]);
				for (int j = 0; j < it; j++)	cout << n - i - 1 << ' ' << n - i << ' ';
				phi[n - i - 1] -= it;
				phi[n - i] -= it;
				if (!phi[n - i]) {
					if (!phi[n - i - 1])	solve(n - i - 2);
					else	solve(n - i - 1);
				}
				else {
					int j = 2;
					for (; n - i - j > 1; j++) {
						if (gcd(n - i, n - i - j) > 1)	continue;
						int it = min(phi[n - i], phi[n - i - j]);
						for (int k = 0; k < it; k++)	cout << n - i - j << ' ' << n - i << ' ';
						phi[n - i] -= it;
						phi[n - i - j] -= it;
						if (!phi[n - i])	break;
					}

					if (!phi[n - i - j])	solve(n - i - j - 1);
					else	solve(n - i - j);
				}
			}

			/*
			int it = min(phi[n], phi[n - 2]);
			for (int i = 0; i < it; i++)	cout << n << ' ' << n - 2 << ' ';
			phi[n - 2] -= it;
			phi[n] -= it;
			if (!phi[n]) {
				if (!phi[n - 2])	solve(n - 3);
				else	solve(n - 2);
			}
			else {

			}
			*/
		}
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

	for (int i = N; i >= 1; i--) {
		if (phi[i])	cout << i << ' ';
	}
}