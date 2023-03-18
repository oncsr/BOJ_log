#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, b;
	string a;
	queue<int> Q;
	for (cin >> n; n--;) {
		cin >> a;
		if (a == "push") {
			cin >> b;
			Q.push(b);
		}
		if (a == "pop") {
			if (Q.empty())	cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		if (a == "size") {
			cout << Q.size() << '\n';
		}
		if (a == "empty") {
			cout << (int)Q.empty() << '\n';
		}
		if (a == "front") {
			cout << (Q.empty() ? -1 : Q.front()) << '\n';
		}
		if (a == "back") {
			cout << (Q.empty() ? -1 : Q.back()) << '\n';
		}
	}
}