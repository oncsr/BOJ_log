#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, X, Y, f = 0, g = 0;
	for (cin >> N >> M >> X >> Y; M--;) {
		int a, b;
		cin >> a >> b;
		if (a)	f++;
		else	g++;
	}

	int S = 1;
	for (int i = 0, j = 9 - f - g; i < N - f - g; i++, j--)	S *= j;
	for (int i = 0, j = N - f; i < g; i++, j--)	S *= j;
	cout << (S - 1) / 3 * Y + S * X;
}