#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	deque<char> left;
	stack<char> right;
	int T;
	for (cin >> T; T--;) {
		string a;
		cin >> a;
		for (char i : a) {
			if (i == '<') {
				if (!left.empty()) {
					right.push(left.back());
					left.pop_back();
				}
			}
			else if (i == '>') {
				if (!right.empty()) {
					left.push_back(right.top());
					right.pop();
				}
			}
			else if (i == '-') {
				if (!left.empty())	left.pop_back();
			}
			else	left.push_back(i);
		}
		while (!left.empty()) {
			cout << left.front();
			left.pop_front();
		}
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << '\n';
	}
}