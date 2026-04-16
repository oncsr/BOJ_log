#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int T;
	for (cin >> T; T--;) {
		int a, b;
		cin >> a >> b;
		swap(s[a], s[b]);
	}
	cout << s;

}