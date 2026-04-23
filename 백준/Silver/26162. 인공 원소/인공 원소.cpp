#include <iostream>
using namespace std;

int main() {
	int N, e[119]{}, a;
	for (int i = 2; i * i <= 118; i++) {
		if (!e[i]) {
			for (int j = i * 2; j <= 118; j += i)	e[j] = 1;
		}
	}
	for (cin >> N; N--;) {
		cin >> a;
		int find = 0, st = 2, ed = a - 2;
		while (st <= ed) {
			if (!e[st] && !e[ed]) {
				find = 1;
				break;
			}
			st++, ed--;
		}
		cout << (find ? "Yes\n" : "No\n");
	}
}