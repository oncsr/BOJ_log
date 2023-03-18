#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	priority_queue<int, vector<int>, greater<> > PQ;
	for (cin >> N; N--;) {
		cin >> a;
		if (!a) {
			if (PQ.empty())	cout << 0 << '\n';
			else {
				cout << PQ.top() << '\n';
				PQ.pop();
			}
			continue;
		}
		PQ.push(a);
	}
}