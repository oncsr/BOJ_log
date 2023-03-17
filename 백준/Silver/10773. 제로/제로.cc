#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	stack<int> S;
	int K, a, s = 0;
	for (cin >> K; K--;) {
		cin >> a;
		a ? S.push(a) : S.pop();
	}
	while (!S.empty())	s += S.top(), S.pop();
	cout << s;
}