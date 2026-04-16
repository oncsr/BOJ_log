#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	if (N == 3)	return cout << -1, 0;
	for (int i = N - (N & 1) - 2; i >= 1; i--)	cout << i << '\n';
	if (N & 1)	cout << N - 1 << '\n' << N << '\n' << N - 2;
	else	cout << N << '\n' << N - 1;

}