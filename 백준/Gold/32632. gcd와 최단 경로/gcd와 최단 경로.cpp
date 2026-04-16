#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int K, N, s = 0;
	cin >> K >> N;
	for (int i = 1; i <= N; i++) {
		if (i == K)	continue;
		int g = gcd(K, i);
		if (g <= 2)	s++;
	}
	cout << s;

}