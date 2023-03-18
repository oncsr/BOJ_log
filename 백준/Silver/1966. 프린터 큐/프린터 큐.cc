#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N, M, a;
		cin >> N >> M;
		queue<ii> Q;
		for (int i = 0; i < N; i++) {
			cin >> a;
			Q.push({ i,a });
		}
		int g = 0;
		while (!Q.empty()) {
			int id = Q.front().first;
			int important = Q.front().second;
			Q.push(Q.front());
			Q.pop();
			int mx = 0;
			while (id != Q.front().first) {
				mx = max(mx, Q.front().second);
				Q.push(Q.front());
				Q.pop();
			}

			if (important >= mx) {
				Q.pop();
				g++;
				if (id == M)	break;
			}
			while (mx > Q.front().second) {
				Q.push(Q.front());
				Q.pop();
			}
			id = Q.front().first;
			Q.pop();
			g++;
			if (id == M)	break;
			
		}
		cout << g << '\n';
	}
}