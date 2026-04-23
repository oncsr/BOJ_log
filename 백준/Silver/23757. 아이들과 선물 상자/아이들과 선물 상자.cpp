#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, a;
	cin >> n >> m;
	priority_queue<int, vector<int>, less<> > Q;
	for (int i = 0; i < n; i++) {
		cin >> a;
		Q.push(a);
	}
	bool suc = true;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (suc) {
			int t = Q.top();
			Q.pop();
			if (t >= a) {
				t -= a;
				if (t)	Q.push(t);
			}
			else	suc = false;
		}
	}
	cout << (suc ? 1 : 0);
}