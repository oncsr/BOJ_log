#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	if (s[1] == '1') {
		if (s[0] == '(')	cout << 0;
		else	cout << 2;
	}
	else	cout << 1;

}