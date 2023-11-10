#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	map<int, int> M;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (!M[a])	M[a] = i;
		else {
			cout << M[a] << ' ' << i;
			return 0;
		}
	}

}