#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b, s = 0;
	priority_queue<int, vector<int>, greater<>>Q;
	for (cin >> n; n--;) {
		cin >> a;
		Q.push(a);
	}
	while (Q.size() > 1) {
		a = Q.top(); Q.pop();
		b = Q.top(); Q.pop();
		Q.push(a + b);
		s += a + b;
	}
	cout << s;
}