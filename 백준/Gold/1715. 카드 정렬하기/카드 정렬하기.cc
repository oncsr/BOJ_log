#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	priority_queue<int, vector<int>, greater<> > PQ;
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		PQ.push(a);
	}
	int s = 0;
	while (PQ.size() > 1) {
		a = PQ.top();
		PQ.pop();
		b = PQ.top();
		PQ.pop();
		s += a + b;
		PQ.push(a + b);
	}
	cout << s;
}