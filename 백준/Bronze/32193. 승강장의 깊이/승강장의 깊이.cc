#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, a = 0, b = 0;
	cin >> N;
	for (int i = 0, c, d; i < N; i++) {
		cin >> c >> d;
		a += c, b += d;
		cout << a - b << '\n';
	}

}