#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, s = 1, now = 1;
	stack<int> S;
	vector<char> V;
	for (cin >> N; N--;) {
		cin >> a;
		while (s <= a) {
			S.push(s++);
			V.push_back('+');
		}
		if (S.empty() || S.top() != a) {
			cout << "NO";
			return 0;
		}
		S.pop();
		V.push_back('-');
	}
	for (char i : V)	cout << i << '\n';
}