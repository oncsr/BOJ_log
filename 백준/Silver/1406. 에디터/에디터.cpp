#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	deque<char> S1;
	stack<char> S2;
	cin >> a;
	for (char i : a)	S1.push_back(i);
	int n;
	char o, b;
	cin >> n;
	while (n--) {
		cin >> o;
		if (o == 'P') {
			cin >> b;
			S1.push_back(b);
		}
		else if (o == 'L') {
			if (!S1.empty()) {
				S2.push(S1.back());
				S1.pop_back();
			}
		}
		else if (o == 'B') {
			if (!S1.empty())	S1.pop_back();
		}
		else if (o == 'D') {
			if (!S2.empty()) {
				S1.push_back(S2.top());
				S2.pop();
			}
		}
	}
	while (!S1.empty()) {
		cout << S1.front();
		S1.pop_front();
	}
	while (!S2.empty()) {
		cout << S2.top();
		S2.pop();
	}
}