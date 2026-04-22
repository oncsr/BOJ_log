#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, temp, a, zero = 0, mn, LL, RR;
	cin >> N >> temp;
	mn = N;
	if (temp == 0)	zero++;
	for (int i = 2; i <= N; i++) {
		cin >> a;
		if (a) {
			if (temp)	continue;
			int L = i - zero - 1;
			int R = N - i + 1;
			if (min(2 * L + R, 2 * R + L) < mn)	LL = L, RR = R, mn = min(2 * L + R, 2 * R + L);
			zero = 0;
		}
		else	zero++;
		temp = a;
	}
	if (zero) {
		if (N - zero < mn)	LL = N - zero, RR = 0, mn = N - zero;
	}
	if (mn == N) {
		cout << N << '\n';
		for (int i = 0; i < N; i++)	cout << 'L';
	}
	else if (LL < RR) {
		cout << 2 * LL + RR << '\n';
		for (int i = 0; i < LL; i++)	cout << 'L';
		for (int i = 0; i < LL + RR; i++)	cout << 'R';
	}
	else {
		cout << 2 * RR + LL << '\n';
		for (int i = 0; i < RR; i++)	cout << 'R';
		for (int i = 0; i < LL + RR; i++)	cout << 'L';
	}
}