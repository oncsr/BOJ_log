#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	char now, prev = ' ';
	int one = 0, zero = 0;
	while (cin >> now) {
		if (now != prev) {
			if (now == '0')	zero++;
			else	one++;
		}
		prev = now;
	}
	cout << min(one, zero);

}