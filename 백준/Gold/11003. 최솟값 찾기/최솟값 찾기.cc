#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, l, a;
	cin >> n >> l;
	deque<int> D;
	priority_queue<int, vector<int>, greater<> > Q1;
	priority_queue<int, vector<int>, greater<> > Q2;
	for (int i = 0; i < n; i++) {
		cin >> a;
		D.push_back(a);
		Q1.push(a);
		if (i >= l) {
			if (Q1.top() == D.front()) {
				Q1.pop();
				while (!Q2.empty() && Q1.top() == Q2.top()) {
					Q1.pop();
					Q2.pop();
				}
			}
			else	Q2.push(D.front());
			D.pop_front();
		}
		cout << Q1.top() << ' ';
	}
}