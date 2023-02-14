#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<ii> ans;

void Hanoi(int n, int now, int dest) {
	if (n == 1) {
		cout << now << ' ' << dest << '\n';
		return;
	}

	if (now == 1) {
		if (dest == 2)	Hanoi(n - 1, now, 3);
		else	Hanoi(n - 1, now, 2);
		cout << now << ' ' << dest << '\n';
		if (dest == 2)	Hanoi(n - 1, 3, 2);
		else	Hanoi(n - 1, 2, 3);
	}
	else if (now == 2) {
		if (dest == 1)	Hanoi(n - 1, now, 3);
		else	Hanoi(n - 1, now, 1);
		cout << now << ' ' << dest << '\n';
		if (dest == 1)	Hanoi(n - 1, 3, 1);
		else	Hanoi(n - 1, 1, 3);
	}
	else {
		if (dest == 1)	Hanoi(n - 1, now, 2);
		else	Hanoi(n - 1, now, 1);
		cout << now << ' ' << dest << '\n';
		if (dest == 1)	Hanoi(n - 1, 2, 1);
		else	Hanoi(n - 1, 1, 2);
	}
}

int main() {
	int N;
	cin >> N;
	cout << ((1 << N) - 1) << '\n';
	Hanoi(N, 1, 3);
}