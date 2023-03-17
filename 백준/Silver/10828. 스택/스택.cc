#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	stack<int> S;
	int N, a;
	string o;
	for (cin >> N; N--;) {
		cin >> o;
		if (o == "push")	cin >> a, S.push(a);
		if (o == "pop") {
			if (S.empty())	cout << "-1\n";
			else	cout << S.top() << '\n', S.pop();
		}
		if (o == "size")	cout << S.size() << '\n';
		if (o == "empty")	cout << (int)S.empty() << '\n';
		if (o == "top") {
			if (S.empty())	cout << "-1\n";
			else	cout << S.top() << '\n';
		}
	}
}