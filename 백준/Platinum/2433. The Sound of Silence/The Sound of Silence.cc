#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, l, a, c;
	cin >> n >> l >> c;
	int D[1000000]{};
	bool ch = false;
	priority_queue<int, vector<int>, greater<> > Q1;
	priority_queue<int, vector<int>, greater<> > Q2;
	priority_queue<int, vector<int>, less<> > Q3;
	priority_queue<int, vector<int>, less<> > Q4;
	for (int i = 0; i < n; i++) {
		cin >> a;
		D[i] = a;
		Q1.push(a);
		Q3.push(a);
		if (i >= l) {
			if (Q1.top() == D[i - l]) {
				Q1.pop();
				while (!Q2.empty() && Q1.top() == Q2.top()) {
					Q1.pop();
					Q2.pop();
				}
			}
			else	Q2.push(D[i - l]);
			if (Q3.top() == D[i - l]) {
				Q3.pop();
				while (!Q4.empty() && Q3.top() == Q4.top()) {
					Q3.pop();
					Q4.pop();
				}
			}
			else	Q4.push(D[i - l]);
		}
		if (i >= l - 1) {
			if (Q3.top() - Q1.top() <= c) {
				cout << i - l + 2 << '\n';
				ch = true;
			}
		}
	}
	if (!ch)	cout << "NONE";
}