#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	while (!(!n && !k && !m)) {
		int s = 1;
		for (int i = 1; i < n; i++) {
			s = (s + k) % (i + 1);
			if (!s)	s = i + 1;
		}
		int g = k % n;
		s -= (g - m);
		if (s < 1)	s += n;
		if (s > n)	s -= n;
		cout << s << '\n';
		cin >> n >> k >> m;
	}
}