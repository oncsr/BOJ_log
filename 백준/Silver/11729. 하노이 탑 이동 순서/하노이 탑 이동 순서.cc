#include <bits/stdc++.h>
using namespace std;

void Hanoi(int n, int now, int dest) {
	if (n == 1) {
		cout << now << ' ' << dest << '\n';
		return;
	}

	int other = 6 - (now + dest);

	Hanoi(n - 1, now, other);
	cout << now << ' ' << dest << '\n';
	Hanoi(n - 1, other, dest);
}

int main() {
	int N;
	cin >> N;
	cout << ((1 << N) - 1) << '\n';
	Hanoi(N, 1, 3);
}