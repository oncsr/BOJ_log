#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<> > Q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i < k)	Q.push(a);
		else {
			Q.push(a);
			cout << Q.top() << ' ';
			Q.pop();
		}
	}
	while (!Q.empty())	cout << Q.top() << ' ', Q.pop();
}