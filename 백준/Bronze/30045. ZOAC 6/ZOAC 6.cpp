#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, ans = 0;
	for (cin >> N; N--;) {
		string a;
		cin >> a;
		for (int i = 0; i < a.size() - 1; i++) {
			string ch = a.substr(i, 2);
			if (ch == "01" || ch == "OI") {
				ans++;
				break;
			}
		}
	}
	cout << ans;

}