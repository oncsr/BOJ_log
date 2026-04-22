#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<long long, vector<long long>, greater<>> Q;
	long long n, m, a, b, s = 0;
	for (cin >> n >> m; n--;) {
		cin >> a;
		Q.push(a);
	}
	for (; m--;) {
		a = Q.top(); Q.pop(); b = Q.top(); Q.pop();
		Q.push(a + b);	Q.push(a + b);
	}
	while (!Q.empty())	s += Q.top(), Q.pop();
	cout << s;
}