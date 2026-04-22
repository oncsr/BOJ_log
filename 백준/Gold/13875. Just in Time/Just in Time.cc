#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	while (N) {
		int T = N, c = 0;
		for (int i = 2; i * i <= T; i++) {
			if (T % i == 0)	c++;
		}
		if (!c) {
			cout << N;
			return 0;
		}
		N--;
	}

}