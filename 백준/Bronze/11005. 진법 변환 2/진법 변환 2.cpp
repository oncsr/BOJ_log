#include <iostream>
#include <stack>
using namespace std;

int main() {
	long long N, B;
	cin >> N >> B;
	long long g = B;
	stack<char> S;
	while (N > 0) {
		long long ch = (N % g) / (g / B);
		if (ch > 9)	S.push('A' + (ch - 10));
		else	S.push('0' + ch);
		N -= (N % g);
		g *= B;
	}
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}