#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int e[10000]{};
	for (int i = 2; i * i < 10000; i++)
		if (!e[i])
			for (int j = i * 2; j < 10000; j += i)
				e[j] = 1;
	int T;
	for (cin >> T; T--;) {
		int A, B;
		cin >> A >> B;
		queue<pair<int, int> > Q;
		int visit[10000]{};
		Q.push({ A,0 });
		visit[A]++;
		bool suc = false;
		while (!Q.empty()) {
			int now = Q.front().first;
			int cnt = Q.front().second;
			Q.pop();
			if (now == B) {
				cout << cnt << '\n';
				suc = true;
				break;
			}
			int a = now / 1000;
			int b = (now / 100) % 10;
			int c = (now / 10) % 10;
			int d = now % 10;
			for (int i = now - a * 1000 + 1000; i < 10000; i += 1000) {
				if (!e[i] && !visit[i]) {
					Q.push({ i,cnt + 1 });
					visit[i]++;
				}
			}
			for (int i = now - b * 100; i / 1000 == now / 1000; i += 100) {
				if (!e[i] && !visit[i]) {
					Q.push({ i,cnt + 1 });
					visit[i]++;
				}
			}
			for (int i = now - c * 10; i / 100 == now / 100; i += 10) {
				if (!e[i] && !visit[i]) {
					Q.push({ i, cnt + 1 });
					visit[i]++;
				}
			}
			for (int i = now - d; i / 10 == now / 10; i++) {
				if (!e[i] && !visit[i]) {
					Q.push({ i,cnt + 1 });
					visit[i]++;
				}
			}
		}
		if (!suc)	cout << "Impossible\n";
	}
}