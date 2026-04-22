#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int j, n, ans = 0;
	cin >> j >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string a;
		getline(cin, a);
		int s = 0;
		for (char i : a) {
			if (i >= 65 && i <= 90)	s += 4;
			else if (i == 32)	s += 1;
			else	s += 2;
		}
		if (s <= j)	ans++;
	}
	cout << ans;
}