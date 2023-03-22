#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	cin >> a;
	stack<char> S;
	int s = 0;
	char temp = ' ';
	for (char i : a) {
		if (i == '(')	S.push(i);
		else if (i == ')') {
			S.pop();
			if (temp == '(')	s += S.size();
			else	s++;
		}
		temp = i;
	}
	cout << s;
}