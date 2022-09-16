#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x;	cin >> n;
	priority_queue<int, vector<int>, greater<> > Q;
	for (; n--;) {
		cin >> x;
		if (x)	Q.push(x);
		else {
			if (Q.empty())	cout << "0\n";
			else {
				cout << Q.top() << '\n';
				Q.pop();
			}
		}
	}
}