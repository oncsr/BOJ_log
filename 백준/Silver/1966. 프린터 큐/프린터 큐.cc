#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	int T;
	for (cin >> T; T--;) {
		int n, m, a, s = 0;
		cin >> n >> m;
		queue<ii> Q;
		priority_queue<int, vector<int>, less<> > Q2;
		for (int i = 0; i < n; i++) {
			cin >> a;
			Q.push({ a,i });
			Q2.push(a);
		}
		while (!Q.empty()) {
			if (Q.front().first != Q2.top()) {
				ii temp = Q.front();
				Q.pop();
				Q.push(temp);
			}
			else {
				s++;
				int idx = Q.front().second;
				Q.pop();
				Q2.pop();
				if (idx == m)	break;
			}
		}
		cout << s << '\n';
	}
}