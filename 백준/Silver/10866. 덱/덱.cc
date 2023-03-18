#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, b;
	string a;
	deque<int> DQ;
	for (cin >> N; N--;) {
		cin >> a;
		if (a == "push_front") {
			cin >> b;
			DQ.push_front(b);
		}
		if (a == "push_back") {
			cin >> b;
			DQ.push_back(b);
		}
		if (a == "pop_front") {
			if (DQ.empty())	cout << -1 << '\n';
			else {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		}
		if (a == "pop_back") {
			if (DQ.empty())	cout << -1 << '\n';
			else {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		}
		if (a == "size") {
			cout << DQ.size() << '\n';
		}
		if (a == "empty") {
			cout << (int)DQ.empty() << '\n';
		}
		if (a == "front") {
			if (DQ.empty())	cout << -1 << '\n';
			else	cout << DQ.front() << '\n';
		}
		if (a == "back") {
			if (DQ.empty())	cout << -1 << '\n';
			else	cout << DQ.back() << '\n';
		}
	}
}