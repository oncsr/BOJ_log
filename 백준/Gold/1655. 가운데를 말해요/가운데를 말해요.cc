#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<int, vector<int>, greater<> > upper;
	priority_queue<int, vector<int>, less<> > lower;
	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (lower.empty())
			lower.push(a);
		else if (upper.empty()) {
			if (a < lower.top()) {
				upper.push(lower.top());
				lower.pop();
				lower.push(a);
			}
			else	upper.push(a);
		}
		else {
			if (a <= upper.top())	lower.push(a);
			else	upper.push(a);
			if (lower.size() > upper.size() + 1) {
				upper.push(lower.top());
				lower.pop();
			}
			else if (upper.size() > lower.size()) {
				lower.push(upper.top());
				upper.pop();
			}
		}
		cout << lower.top() << '\n';
	}

}