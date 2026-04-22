#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, x = 0, odd = 0, even = 0;

	for (cin >> N >> Q; Q--;) {
		int a, b;
		cin >> a;
		if (a == 1) {
			cin >> b;
			x = (x + b + N) % N;
		}
		else {
			
			if (x & 1) {
				if (even)	even--;
				else	odd++;
				x = (x - 1 + N) % N;
			}
			else {
				if (odd)	odd--;
				else	even++;
				x = (x + 1 + N) % N;
			}
		}
	}
	odd %= (N / 2), even %= (N / 2);
	int arr[100001]{};
	for (int i = x, s = 1; i < x + N; i += 2, s += 2)	arr[i % N] = s;
	for (int i = x + N + 1 + (odd - even) * 2, s = 2; i < x + 1 + (odd - even) * 2 + N * 2; i += 2, s += 2)	arr[i % N] = s;
	for (int i = 0; i < N; i++)	cout << arr[i] << ' ';
}