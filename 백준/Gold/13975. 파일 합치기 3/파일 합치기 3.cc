#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		priority_queue<ll, vector<ll>, greater<> > PQ;
		int K;
		ll a, b, s = 0;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> a;
			PQ.push(a);
		}
		while (PQ.size() > 1) {
			a = PQ.top();
			PQ.pop();
			b = PQ.top();
			PQ.pop();
			s += a + b;
			PQ.push(a + b);
		}
		cout << s << '\n';
	}
}