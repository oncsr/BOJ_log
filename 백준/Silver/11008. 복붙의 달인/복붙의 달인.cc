#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int ans = 0;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++) {
			if (i + b.size() <= a.size()) {
				if (a.substr(i, b.size()) == b) {
					ans++;
					i = i + b.size() - 1;
				}
				else	ans++;
			}
			else	ans++;
		}
		cout << ans << '\n';
	}
	
}