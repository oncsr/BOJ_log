#include <bits/stdc++.h>
using namespace std;

int N, x = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0, a, b; i < N; i++) {
		cin >> a >> b;
		if (b & 1) x ^= (a & 1);
		else {
			a %= (b + 1);
			if (a == b) x ^= 2;
			else x ^= (a & 1);
		}
	}
	cout << (x ? "Alice" : "Bob");

}