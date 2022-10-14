#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, start, end, n, t, x, d1, d2, d3, d4;
	string s;
	for (cin >> T; T--;) {
		cin >> start >> end;
		int visit[10000]{};
		queue<pair<pair<int, int>, string>>Q;
		Q.push({ {start,0},"" });
		visit[start]++;
		while (!Q.empty()) {
			n = Q.front().first.first;
			t = Q.front().first.second;
			s = Q.front().second;
			Q.pop();
			if (n == end)	break;
			x = (n * 2) % 10000;
			if (!visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + 'D' });
			}
			x = n - 1;
			if (x < 0)	x = 9999;
			if (!visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + 'S' });
			}
			
			x = n;
			d1 = x / 1000;
			x %= 1000;
			d2 = x / 100;
			x %= 100;
			d3 = x / 10;
			x %= 10;
			d4 = x;
			x = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
			if (!visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + 'L' });
			}
			x = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
			if (!visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + 'R' });
			}

		}
		cout << s << '\n';
	}
}