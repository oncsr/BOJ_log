#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int a[301]{};
	for (int i = 1; i <= 300; i++) {
		a[i] = a[i - 1];
		if (i == 60 || i == 100 || i == 140 || i == 200 || i == 250)	a[i]++;
	}
	int b[100]{};
	for (int i = 0; i < N; i++)	cin >> b[i];
	sort(b, b + N, greater<>());
	int c = 0, d = 0;
	for (int i = 0; i < min(42, N); i++)	c += b[i], d += a[b[i]];
	cout << c << ' ' << d;
	
}