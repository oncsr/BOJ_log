#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	stack<int> S;
	for (char i : s) {
		if ('0' <= i && i <= '9') { S.push(i - '0'); continue; }
		int b = S.top();	S.pop();
		int a = S.top();	S.pop();
		int res;
		if (i == '*')	res = a * b;
		else if (i == '/')	res = a / b;
		else if (i == '-')	res = a - b;
		else	res = a + b;
		S.push(res);
	}
	cout << S.top();

}