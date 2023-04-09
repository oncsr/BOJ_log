#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string c;	getline(cin, c);
	while (c != ".") {
		bool chk = true;
		stack<char> S;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] == '(' || c[i] == '[')
				S.push(c[i]);
			if ((c[i] == ')' || c[i] == ']') && S.empty()) {
				chk = false;
				break;
			}
			else if ((c[i] == ')' && S.top() == '(') || (c[i] == ']' && S.top() == '['))
				S.pop();
			else if (c[i] == ')' || c[i] == ']') {
				chk = false;
				break;
			}
		}
		if (chk && S.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
		getline(cin, c);
	}
}