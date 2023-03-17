#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	getline(cin, a);
	while (a != ".") {
		stack<char> S;
		for (char i : a) {
			if (i == '(')	S.push(i);
			if (i == '[')	S.push(i);
			if (i == ')') {
				if (S.empty() || S.top() != '(') {
					S.push('e');
					break;
				}
				S.pop();
			}
			if (i == ']') {
				if (S.empty() || S.top() != '[') {
					S.push('e');
					break;
				}
				S.pop();
			}
		}
		cout << (S.empty() ? "yes\n" : "no\n");
		getline(cin, a);
	}
}