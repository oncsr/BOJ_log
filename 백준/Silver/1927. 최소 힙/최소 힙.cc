#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> q;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x)
			q.push(x);
		else {
			if (q.empty())
				cout << "0\n";
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
}