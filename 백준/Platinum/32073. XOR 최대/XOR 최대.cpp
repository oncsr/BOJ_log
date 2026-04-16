#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		int one = -1, fin = 0, zero = 0;
		queue<int> Q;
		for (int i = 0; i < N; i++) {
			char _;
			cin >> _;
			int a = _ - '0';
			if (!a)	zero++;
			if (one == -1) {
				if (a)	Q.push(a), one = 1, cout << 1;
			}
			else {
				if (!fin) {
					if (!a) {
						fin = 1;
						Q.pop();
						cout << 1;
					}
					else if (!zero && i == N - 1)	cout << 0;
					else	cout << 1, one++;
				}
				else {
					if (one && !Q.front())	one = 0;
					if (a && Q.front() && one) {
						one = 0;
						while (Q.front())	Q.pop();
					}
					cout << (a ^ Q.front()), Q.pop();
				}
				Q.push(a);
			}
		}
		if (one == -1)	cout << 0;
		cout << '\n';
	}

}