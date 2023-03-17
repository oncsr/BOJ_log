#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		stack<char> S;
		string a;
		cin >> a;
		for (char i : a) {
			if (i == '(')	S.push(i);
			else {
				if (S.empty()) {
					S.push('e');
					break;
				}
				S.pop();
			}
		}
		cout << (S.empty() ? "YES\n" : "NO\n");
	}
}