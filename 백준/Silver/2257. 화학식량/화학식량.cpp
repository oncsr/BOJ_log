#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a;
	cin >> a;
	stack<int> S;
	map<char, int> M;
	M['H'] = 1, M['C'] = 12, M['O'] = 16;
	for (char i : a) {
		if ('2' <= i && i <= '9') {
			int t = S.top();
			S.pop();
			S.push(t * (i - '0'));
		}
		else if (i == '(')	S.push(-1);
		else if (i == ')') {
			int t = 0;
			while (S.top() != -1) {
				t += S.top();
				S.pop();
			}
			S.pop();
			S.push(t);
		}
		else	S.push(M[i]);
	}
	int ans = 0;
	while (!S.empty())	ans += S.top(), S.pop();
	cout << ans;

}