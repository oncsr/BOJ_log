#include <iostream>
#include <cmath>
using namespace std;

int N;

void sol(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)	return;
	}
	if ((int)log10(n) == N - 1) {
		cout << n << '\n';
		return;
	}
	sol(n * 10 + 1);
	sol(n * 10 + 3);
	sol(n * 10 + 7);
	sol(n * 10 + 9);
}

int main() {
	cin >> N;
	sol(2);	sol(3);	sol(5);	sol(7);
}