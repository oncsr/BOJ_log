#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	queue<int> Q;
	int N;
	for (cin >> N; N--;) {
		string a;
		int b;
		cin >> a;
		if (a == "push") {
			cin >> b;
			Q.push(b);
		}
		else if (a == "pop") {
			if (Q.empty())	cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (a == "size")
			cout << Q.size() << '\n';
		else if (a == "empty")
			cout << (int)Q.empty() << '\n';
		else if (a == "front")
			cout << (Q.empty() ? -1 : Q.front()) << '\n';
		else
			cout << (Q.empty() ? -1 : Q.back()) << '\n';
	}
}