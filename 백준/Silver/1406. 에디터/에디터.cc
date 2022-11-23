#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	stack<char> S1;
	stack<char> S2;
	cin >> a;
	for (char i : a)	S1.push(i);
	int n;
	char o, b;
	cin >> n;
	while (n--) {
		cin >> o;
		if (o == 'P') {
			cin >> b;
			S1.push(b);
		}
		else if (o == 'L') {
			if (!S1.empty()) {
				S2.push(S1.top());
				S1.pop();
			}
		}
		else if (o == 'B') {
			if (!S1.empty())	S1.pop();
		}
		else if (o == 'D') {
			if (!S2.empty()) {
				S1.push(S2.top());
				S2.pop();
			}
		}
	}
	char ans[600001]{};
	int f = S1.size();
	while (!S1.empty()) {
		ans[--f] = S1.top();
		S1.pop();
	}
	cout << ans;
	while (!S2.empty()) {
		cout << S2.top();
		S2.pop();
	}
}