#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string S;
	for (cin >> S; S != "end"; cin >> S) {
		int x = 0, o = 0;
		for (char i : S)	x += i == 'X', o += i == 'O';
		if (o > x || x > o + 1) {
			cout << "invalid\n";
			continue;
		}
		int xb = 0, ob = 0;
		string arr[8] = { "036","147","258","012","345","678","048","246" };
		for (int i = 0; i < 8; i++) {
			int tx = 0, to = 0;
			for (int j = 0; j < 3; j++) {
				tx += S[arr[i][j] - '0'] == 'X';
				to += S[arr[i][j] - '0'] == 'O';
			}
			if (tx == 3)	xb++;
			if (to == 3)	ob++;
		}
		if (xb && ob) {
			cout << "invalid\n";
			continue;
		}
		if (!xb && !ob) {
			if (x + o == 9)	cout << "valid\n";
			else	cout << "invalid\n";
			continue;
		}
		if (xb && x == o) {
			cout << "invalid\n";
			continue;
		}
		if (ob && x > o) {
			cout << "invalid\n";
			continue;
		}
		cout << "valid\n";
	}
}