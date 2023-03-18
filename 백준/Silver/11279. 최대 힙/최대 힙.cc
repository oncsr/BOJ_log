#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	priority_queue<int, vector<int>, less<> > PQ;
	for (cin >> N; N--;) {
		int x;
		cin >> x;
		if (x)	PQ.push(x);
		else {
			if (PQ.empty())	cout << 0 << '\n';
			else {
				cout << PQ.top() << '\n';
				PQ.pop();
			}
		}
	}
}